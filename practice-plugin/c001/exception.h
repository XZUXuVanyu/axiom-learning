#pragma once
#include "numeric_tools.h"
#include <source_location>
#include <string>
namespace axiom
{
	class exception : public std::exception
	{
	public:
		exception(std::string message, std::source_location location);
		virtual ~exception() = default;
		virtual [[nodiscard]] const char* what() const override;

	private:
		const std::source_location m_location;
		std::string m_message;
	};

	class range_exception : public exception
	{
	public:
		range_exception(operation_type opt_type, int32_t opt1, int32_t opt2, 
			std::source_location location);
		~range_exception() = default;

		operation_type get_type() const;
	private:
		const operation_type m_opt_type;
		const int32_t m_opt1;
		const int32_t m_opt2;
	};
}