#include "DX3D/Core/Base.hpp"

dx3d::Base::Base( const BaseDesc& desc )
	: m_logger( desc.logger )
{}

dx3d::Base::~Base()
{}

dx3d::Logger& dx3d::Base::getLogger() const noexcept
{
	return m_logger;
}
