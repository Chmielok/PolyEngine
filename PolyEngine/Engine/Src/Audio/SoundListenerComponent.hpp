#pragma once

#include "ECS/ComponentBase.hpp"
#include <Math/Vector.hpp>
#include <Collections/Dynarray.hpp>
#include "Audio/SoundEmitterComponent.hpp"

namespace Poly
{
	class SoundWorldComponent;

	/// Contains information about listener.
	/// There can be any number of listeners but every listener has its own copy of every emitter (except of resources)
	/// hence 10 listeners uses 10 times more CPU and memory than 1 listener.
	/// @see SoundEmitterComponent
	class ENGINE_DLLEXPORT SoundListenerComponent : public ComponentBase
	{
	public:
		/// Sets everything to 0 and copies SourcesArray from SoundWorldComponent
		SoundListenerComponent(SoundWorldComponent* worldComponent);
		~SoundListenerComponent();

		float GetGain() const { return Gain; }

	private:
		float Gain = 1;
		Vector Position;
		Vector Velocity;
		Dynarray<SoundEmitterComponent*> Emitters;
	};

} // namespace Poly