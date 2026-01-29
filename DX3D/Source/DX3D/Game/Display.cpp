#include "DX3D/Game/Display.hpp"
#include "DX3D/Graphics/RenderSystem.hpp"

dx3d::Display::Display( const DisplayDesc& desc )
	: Window( desc.window )
{
	m_swapChain = desc.renderSystem.createSwapChain( { m_handle, m_size } );
}
