#pragma once

#include "Common/GLUtils.hpp"

namespace Poly
{
	struct PrimitiveCube : public BaseObject<>
	{
		PrimitiveCube();
		~PrimitiveCube();
	
		GLuint VAO = 0;
		GLuint VBO = 0;
	};
}