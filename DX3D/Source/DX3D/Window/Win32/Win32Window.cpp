#define WIN32_LEAN_AND_MEAN

#include "DX3D/Window/Window.hpp"
#include <Windows.h>
#include <stdexcept>
#include <format>


static LRESULT CALLBACK WindowProcedure( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam )
{
	switch( msg )
	{
		case WM_CLOSE:
			PostQuitMessage( EXIT_SUCCESS );
			break;

		default:
			return DefWindowProc( hwnd, msg, wparam, lparam );
	}

	return EXIT_SUCCESS;
}


dx3d::Window::Window( const WindowDesc& desc )
	: Base( desc.base ), m_size( desc.size )
{
	auto registerWindowClassFunction = []()
	{
		WNDCLASSEX wc{
			.cbSize = sizeof( WNDCLASSEX ),
			.lpfnWndProc = &WindowProcedure,
			.lpszClassName = L"DX3DWindow",
		};
		return RegisterClassEx( &wc );
	};

	static const auto windowClassId = std::invoke( registerWindowClassFunction );
	if( !windowClassId ) DX3DLogErrorAndThrow( "RegisterClassEx failed." );

	RECT rc{ 0, 0, m_size.width, m_size.height };
	AdjustWindowRectEx( &rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false, NULL );
	DX3DLogInfo( std::format( "AdjustWindowRectEx result: Left {}, Right {}, Top {}, Bottom {}.\tTotal size: {}x{}",
							  rc.left, rc.right, rc.top, rc.bottom, (rc.right - rc.left), (rc.bottom - rc.top) ).c_str() );


	m_handle = CreateWindowEx(
		NULL, MAKEINTATOM( windowClassId ), L"DX11Triangle",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top,
		nullptr, nullptr, nullptr, nullptr
	);
	if( !m_handle ) DX3DLogErrorAndThrow( "CreateWindowEx failed." );

	ShowWindow( static_cast<HWND>(m_handle), SW_SHOW );
}

dx3d::Window::~Window()
{
	DX3DLogInfo( "Window deallocation started..." );

	DestroyWindow( static_cast<HWND>(m_handle) );

	DX3DLogInfo( "Window deallocated successfully!" );
}
