#pragma once
#include "DX3D/Core/Base.hpp"

namespace dx3d
{
	class Window : public Base {
	public:

		Window();
		virtual ~Window() override;


	private:

		void* m_handle{};

	};
}
