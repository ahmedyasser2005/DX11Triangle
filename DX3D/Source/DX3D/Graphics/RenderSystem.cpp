#include "DX3D/Graphics/RenderSystem.hpp"
#include "DX3D/Graphics/GraphicsLogUtils.hpp"
#include "DX3D/Graphics/SwapChain.hpp"

dx3d::RenderSystem::RenderSystem( const RenderSystemDesc& desc )
	: Base( desc.base )
{
	DX3DLogInfo( "RenderSystem initilization started..." );

	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	DX3DGraphicsLogErrorAndThrow( D3D11CreateDevice( nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags,
													 nullptr, 0, D3D11_SDK_VERSION,
													 &m_d3dDevice, &featureLevel, &m_d3dContext ), "D3D11CreateDevice failed." );

	DX3DGraphicsLogErrorAndThrow( m_d3dDevice->QueryInterface( IID_PPV_ARGS( &m_dxdgiDevice ) ), "QueryInterface failed to retrieve IDXDGIDevice." );
	DX3DGraphicsLogErrorAndThrow( m_dxdgiDevice->GetParent( IID_PPV_ARGS( &m_dxdgiAdapter ) ), "GetParent failed to retrieve DXDGIAdapter." );
	DX3DGraphicsLogErrorAndThrow( m_dxdgiAdapter->GetParent( IID_PPV_ARGS( &m_dxdgiFactory ) ), "GetParent failed to retrieve DXDGIFactory." );

	DX3DLogInfo( "RenderSystem initilized successfuly." );
}

dx3d::RenderSystem::~RenderSystem()
{
	DX3DLogInfo( "RenderSystem deallocated successfuly." );
}

dx3d::SwapChainPtr dx3d::RenderSystem::createSwapChain( const SwapChainDesc& desc ) const
{
	return std::make_shared<SwapChain>( desc, getGraphicsResourceDesc() );
}

dx3d::GraphicsResourceDesc dx3d::RenderSystem::getGraphicsResourceDesc() const noexcept
{
	return { { getLogger() }, *m_d3dDevice.Get(), *m_dxdgiFactory.Get() };
}