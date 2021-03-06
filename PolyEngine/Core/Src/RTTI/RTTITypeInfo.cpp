#include "CorePCH.hpp"
#include "RTTITypeInfo.hpp"

namespace Poly {
	namespace RTTI {
		const TypeInfo TypeInfo::INVALID = TypeInfo();

		namespace Impl {

			TypeManager& TypeManager::Get() {
				static TypeManager instance;
				return instance;
			}

			TypeInfo TypeManager::RegisterOrGetType(const char* name, const Dynarray<TypeInfo>& baseClassList) {
				if (NameToTypeMap.find(name) != NameToTypeMap.end())
					return NameToTypeMap[name];
				else {
					TypeInfo ti(++Counter);
					NameToTypeMap.insert(std::make_pair(name, ti));
					TypeToNameMap.insert(std::make_pair(ti, name));
					InheritanceListMap[ti] = baseClassList;
					return ti;
				}
			}

			bool TypeManager::IsTypeDerivedFrom(const TypeInfo& checked, const TypeInfo& from) const {
				ASSERTE(checked.IsValid(), "Checked type is not a valid TypeInfo");
				ASSERTE(from.IsValid(), "From type is not a valid TypeInfo");

				if (checked == from)
					return true;

				for (auto& base : InheritanceListMap.at(checked)) {
					ASSERTE(base.IsValid(), "Base type is not a valid TypeInfo");
					if (from == base)
						return true;
				}

				return false;
			}

			const char* TypeManager::GetTypeName(const TypeInfo& typeInfo) const
			{
				const auto& it = TypeToNameMap.find(typeInfo);
				ASSERTE(it != TypeToNameMap.end(), "Type has no name! Not registered?");
				return it->second;
			}

		} // namespace Impl

		TypeInfo::TypeInfo(long long id) : ID(id) {}

		const char* TypeInfo::GetTypeName() const { return Impl::TypeManager::Get().GetTypeName(*this); }

		//------------------------------------------------------------------------------
		std::ostream& operator<< (std::ostream& stream, const TypeInfo& typeInfo) {
			return stream << "TypeInfo["<< typeInfo.ID << ", " << typeInfo.GetTypeName() << "]";
		}
	} // namespace RTTI
} // namespace Poly