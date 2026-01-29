#pragma once
#include "DX3D/Core/Core.hpp"
#include "DX3D/Core/Logger.hpp"
#include "DX3D/Math/Rect.hpp"

namespace dx3d
{
	struct BaseDesc {

		Logger& logger;

	};

	typedef struct {

		BaseDesc base;

	} GraphicsEngineDesc, RenderSystemDesc;

	struct WindowDesc {

		BaseDesc base;
		Rect size{};

	};

	struct DisplayDesc {

		WindowDesc window;
		RenderSystem& renderSystem;

	};

	struct SwapChainDesc {

		void* winHandle{};
		Rect winSize{};

	};

	struct GameDesc {
		Rect windowSize{ 1280,720 };
		Logger::LogLevel logLevel = Logger::LogLevel::Info;
	};

}