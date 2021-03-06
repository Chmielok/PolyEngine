#pragma once

#include "Pipeline/RenderingPassBase.hpp"
#include "Common/GLShaderProgram.hpp"
#include "Common/PrimitiveCube.hpp"

namespace Poly
{
	class World;
	class RenderingTargetBase;
	class GLTextureDeviceProxy;
	class AARect;
	class SkyboxWorldComponent;

	class SkyboxRenderingPass : public RenderingPassBase
	{
	public:
		SkyboxRenderingPass(const PrimitiveCube* cube);

	protected:
		void OnRun(World* world, const CameraComponent* camera, const AARect& /*rect*/, ePassType passType) override;

		void RenderSkybox(const CameraComponent* camera, const SkyboxWorldComponent* SkyboxWorldCmp);

		const PrimitiveCube* Cube;
	};
}