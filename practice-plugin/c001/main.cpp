#include "output.h"
#include "exception.h"
#include "iostream"
#include "numeric_tools.h"

int main()
{
	std::source_location another_location = std::source_location::current();
	try
	{
		std::cout << axiom::numeric::add(1, 3) << std::endl;
		std::cout << axiom::numeric::add(INT32_MAX, 0) << std::endl;
		std::cout << axiom::numeric::add(INT32_MIN, 0) << std::endl;
		std::cout << axiom::numeric::add(INT32_MAX, 1) << std::endl;
		std::cout << axiom::numeric::add(INT32_MIN, -1) << std::endl;
	}
	catch (const axiom::range_exception& e)
	{
		if (e.get_type() == axiom::operation_type::numeric_add)
		{
			std::cout << "numeric add failed: " << e.what() << std::endl;
		}
	}
}