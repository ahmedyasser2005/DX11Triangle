#pragma once
#include "DX3D/Core/Core.hpp"
#include "DX3D/Core/Base.hpp"

namespace dx3d
{
	class GraphicsEngine final : public Base {
	public:

		explicit GraphicsEngine( const GraphicsEngineDesc& desc );
		virtual ~GraphicsEngine() override;

		RenderSystem& getRenderSystem() const noexcept;

	private:

		std::unique_ptr<RenderSystem> m_renderSystem{};

	};
}

