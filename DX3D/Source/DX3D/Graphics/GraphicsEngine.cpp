#include "DX3D/Graphics/GraphicsEngine.hpp"
#include "DX3D/Graphics/RenderSystem.hpp"

dx3d::GraphicsEngine::GraphicsEngine( const GraphicsEngineDesc& desc )
	: Base( desc.base )
{
	getLogger().log( dx3d::Logger::LogLevel::Info, "GraphicsEngine initilization started..." );

	m_renderSystem = std::make_unique<RenderSystem>( RenderSystemDesc{ getLogger() } );

	getLogger().log( dx3d::Logger::LogLevel::Info, "GraphicsEngine initilized successfuly." );
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
	getLogger().log( dx3d::Logger::LogLevel::Info, "GraphicsEngine deallocated successfuly." );
}
