#pragma once
#include "DX3D/Graphics/GraphicsResource.hpp"
#include <wrl.h>

namespace dx3d
{
	class SwapChain final : public GraphicsResource {
	public:

		SwapChain( const SwapChainDesc& sDesc, const GraphicsResourceDesc& gDesc );

	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain{};
	};

}

