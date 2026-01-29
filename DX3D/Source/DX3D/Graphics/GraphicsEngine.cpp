#include "DX3D/Graphics/GraphicsEngine.hpp"
#include "DX3D/Graphics/RenderSystem.hpp"

dx3d::GraphicsEngine::GraphicsEngine( const GraphicsEngineDesc& desc )
	: Base( desc.base )
{

	{
		SwapChainPtr sc{};
		{
			auto sys = std::make_unique<RenderSystem>( RenderSystemDesc{ getLogger() } );
			sc = sys->createSwapChain( {} );
		}
	}


	DX3DLogInfo( "GraphicsEngine initilization started..." );

	m_renderSystem = std::make_unique<RenderSystem>( RenderSystemDesc{ getLogger() } );

	DX3DLogInfo( "GraphicsEngine initilized successfuly." );
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
	DX3DLogInfo( "GraphicsEngine deallocated successfuly." );
}

dx3d::RenderSystem& dx3d::GraphicsEngine::getRenderSystem() const noexcept
{
	return *m_renderSystem;
}
