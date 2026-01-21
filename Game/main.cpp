#include "DX3D/All.hpp"

int main()
{
	try
	{
		dx3d::Game TheGame( { dx3d::Logger::LogLevel::Info } );
		TheGame.run();
	}
	catch( const std::runtime_error& )
	{
		return EXIT_FAILURE;
	}
	catch( const std::exception& )
	{
		return EXIT_FAILURE;
	}
	catch( ... )
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}