#pragma once
#include "DX3D/Core/Base.hpp"

namespace dx3d
{
	class Window final : public Base {
	public:

		explicit Window(const WindowDesc& desc);
		virtual ~Window() override;

	private:

		void* m_handle{};

	};
}
