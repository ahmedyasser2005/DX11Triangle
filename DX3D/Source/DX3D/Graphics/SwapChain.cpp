#include "DX3D/Graphics/SwapChain.hpp"

dx3d::SwapChain::SwapChain( const SwapChainDesc& sDesc, const GraphicsResourceDesc& gDesc )
	: GraphicsResource( gDesc )
{
	DXGI_SWAP_CHAIN_DESC dxgiDesc{};
	dxgiDesc.BufferDesc.Width = std::max( 1, sDesc.winSize.width );
	dxgiDesc.BufferDesc.Height = std::max( 1, sDesc.winSize.height );
	dxgiDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	dxgiDesc.BufferCount = 2;
	dxgiDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

	dxgiDesc.OutputWindow = static_cast<HWND>(sDesc.winHandle);
	dxgiDesc.SampleDesc.Count = 1;
	dxgiDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	dxgiDesc.Windowed = TRUE;

	//DX3DGraphicsLogErrorAndThrow( m_factory.CreateSwapChain( &m_device, &dxgiDesc, &m_swapChain ), "CreateSwapChain failed." );
}
