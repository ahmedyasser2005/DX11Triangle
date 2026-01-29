#pragma once
#include "DX3D/Graphics/GraphicsResource.hpp"
#include "DX3D/Core/Common.hpp"
#include "DX3D/Core/Base.hpp"
#include <d3d11.h>
#include <wrl.h>

namespace dx3d
{
	class RenderSystem final : public Base {
	public:

		explicit RenderSystem( const RenderSystemDesc& desc );
		virtual ~RenderSystem() override;

		SwapChainPtr createSwapChain( const SwapChainDesc& desc ) const;

	private:

		GraphicsResourceDesc getGraphicsResourceDesc() const noexcept;

		Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice{};
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_d3dContext{};
		Microsoft::WRL::ComPtr<IDXGIDevice> m_dxdgiDevice{};
		Microsoft::WRL::ComPtr<IDXGIAdapter> m_dxdgiAdapter{};
		Microsoft::WRL::ComPtr<IDXGIFactory> m_dxdgiFactory{};

	};
}

