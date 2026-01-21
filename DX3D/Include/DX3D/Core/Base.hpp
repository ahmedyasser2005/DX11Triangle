#pragma once
#include "DX3D/Core/Common.hpp"

namespace dx3d
{
	class Base {
	public:

		explicit Base( const BaseDesc& desc );
		virtual ~Base();

		virtual Logger& getLogger() const noexcept final;

	protected:

		Base( const Base& ) = delete;
		Base( Base&& ) = delete;
		Base& operator=( const Base& ) = delete;
		Base& operator=( Base&& ) = delete;

	private:

		Logger& m_logger;

	};
}
