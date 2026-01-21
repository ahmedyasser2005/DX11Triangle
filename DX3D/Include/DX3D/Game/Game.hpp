#pragma once
#include "DX3D/Core/Base.hpp"
#include "DX3D/Core/Core.hpp"

namespace dx3d
{
	class Game : public Base {
	public:

		Game();
		virtual ~Game() override;

		virtual void run() final;

	private:

		std::unique_ptr<Window> m_display{};
		bool m_isRunning{ true };

	};
}
