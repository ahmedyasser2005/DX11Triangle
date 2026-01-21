#include "DX3D/Game/Game.hpp"
#include "DX3D/Window/Window.hpp"

dx3d::Game::Game()
{
	m_display = std::make_unique<Window>();
}

dx3d::Game::~Game()
{
}
