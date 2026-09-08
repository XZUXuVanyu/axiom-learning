#include "numeric_tools.h"
#include "exception.h"

int32_t axiom::numeric::add(int32_t a, int32_t b, const std::source_location& location)
{
	int64_t result = a;
	result += b;

	if (!(result >= std::numeric_limits<int32_t>::min() && result <= std::numeric_limits<int32_t>::max()))
	{
		throw range_exception(operation_type::numeric_add ,a, b, location);
	}

	return result;
}