#include "DX3D/Game/Game.hpp"
#include "DX3D/Game/Display.hpp"
#include "DX3D/Graphics/GraphicsEngine.hpp"

dx3d::Game::Game( const GameDesc& desc )
	:
	Base( { *std::make_unique<Logger>( desc.logLevel ).release() } ),
	m_loggerPtr( &getLogger() )
{
	DX3DLogInfo( "Game initilization started..." );

	m_graphicsEngine = std::make_unique<GraphicsEngine>( GraphicsEngineDesc{ getLogger() } );
	m_display = std::make_unique<Display>( DisplayDesc{ { getLogger(), desc.windowSize }, m_graphicsEngine->getRenderSystem() } );

	DX3DLogInfo( "Game initilized successfuly." );
}

dx3d::Game::~Game()
{
	DX3DLogInfo( "Game deallocated successfuly." );
}
