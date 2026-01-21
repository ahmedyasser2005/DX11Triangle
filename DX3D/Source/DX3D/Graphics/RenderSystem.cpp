#include "DX3D/Graphics/RenderSystem.hpp"

dx3d::RenderSystem::RenderSystem( const RenderSystemDesc& desc )
	: Base( desc.base )
{
	getLogger().log( dx3d::Logger::LogLevel::Info, "RenderSystem initilization started..." );

	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	auto hr = D3D11CreateDevice( nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags,
								 nullptr, 0, D3D11_SDK_VERSION,
								 &m_d3dDevice, &featureLevel, &m_d3dContext );

	if( FAILED( hr ) )
	{
		getLogger().log( dx3d::Logger::LogLevel::Error, "D3D11CreateDevice failed." );
		throw std::runtime_error( "D3D11CreateDevice failed." );
	}

	getLogger().log( dx3d::Logger::LogLevel::Info, "RenderSystem initilized successfuly." );
}

dx3d::RenderSystem::~RenderSystem()
{
	getLogger().log( dx3d::Logger::LogLevel::Info, "RenderSystem deallocated successfuly." );
}
