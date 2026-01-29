#pragma once
#include "DX3D/Core/Core.hpp"
#include "DX3D/Core/Base.hpp"

namespace dx3d
{
	class Game final : public Base {
	public:

		explicit Game( const GameDesc& desc );
		virtual ~Game() override;

		virtual void run() final;

	private:

		std::unique_ptr<Logger> m_loggerPtr{};
		std::unique_ptr<GraphicsEngine> m_graphicsEngine{};
		std::unique_ptr<Display> m_display{};
		bool m_isRunning{ true };

	};
}
