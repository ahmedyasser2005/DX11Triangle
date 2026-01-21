#pragma once
#include "DX3D/Core/Core.hpp"
#include "DX3D/Core/Logger.hpp"

namespace dx3d
{
	struct BaseDesc {

		Logger& logger;

	};

	typedef struct {
		BaseDesc base;
	} WindowDesc, GraphicsEngineDesc, RenderSystemDesc;

	struct GameDesc {
		Logger::LogLevel logLevel = Logger::LogLevel::Info;
	};

}