#pragma once
#include "DX3D/Window/Window.hpp"

namespace dx3d
{
	class Display final : public Window {
	public:

		explicit Display(const DisplayDesc& desc);


	private:

		SwapChainPtr m_swapChain{};

	};
}
