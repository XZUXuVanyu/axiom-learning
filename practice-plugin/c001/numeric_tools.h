#pragma once
#include <source_location>
namespace axiom
{
	enum class operation_type : uint8_t
	{
		numeric_add = 0,
	};

	namespace numeric
	{
		int32_t add(int32_t a, int32_t b,
			const std::source_location& location = std::source_location::current());

	}
}