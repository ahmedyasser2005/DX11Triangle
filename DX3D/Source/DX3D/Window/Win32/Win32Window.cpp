#include "DX3D/Window/Window.hpp"
#include <Windows.h>
#include <stdexcept>


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


dx3d::Window::Window() : Base()
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
	if( !windowClassId ) throw std::runtime_error( "RegisterClassEx failed." );

	RECT rc{ 0, 0, 1280, 720 };
	AdjustWindowRectEx( &rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false, NULL );

	m_handle = CreateWindowEx(
		NULL, MAKEINTATOM( windowClassId ), L"DX11Triangle",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top,
		nullptr, nullptr, nullptr, nullptr
	);
	if( !m_handle ) throw std::runtime_error( "CreateWindowEx failed." );

	ShowWindow( static_cast<HWND>(m_handle), SW_SHOW );
}

dx3d::Window::~Window()
{
	DestroyWindow( static_cast<HWND>(m_handle) );
}
