#include "DX3D/Game/Game.hpp"
#include "DX3D/Window/Window.hpp"
#include "DX3D/Graphics/GraphicsEngine.hpp"

dx3d::Game::Game( const GameDesc& desc )
	:
	Base( { *std::make_unique<Logger>( desc.logLevel ).release() } ),
	m_loggerPtr( &getLogger() )
{
	getLogger().log( dx3d::Logger::LogLevel::Info, "Game initilization started..." );

	m_graphicsEngine = std::make_unique<GraphicsEngine>( GraphicsEngineDesc{ getLogger() } );
	m_display = std::make_unique<Window>( WindowDesc{ getLogger() } );

	getLogger().log( dx3d::Logger::LogLevel::Info, "Game initilized successfuly." );
}

dx3d::Game::~Game()
{
	getLogger().log( dx3d::Logger::LogLevel::Info, "Game deallocated successfuly." );
}
