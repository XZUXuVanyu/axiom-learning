#include "exception.h"
axiom::exception::exception(std::string message, std::source_location location)
	: m_location(location), m_message(message)
{
	std::string file_name = m_location.file_name();
	std::string line_name = std::to_string(m_location.line());
	std::string func_name = m_location.function_name();
	m_message = "[axiom] error at: " + file_name + ", line: " + line_name + "\n" + "func: " + func_name + "\n" + m_message;
}

const char* axiom::exception::what() const noexcept
{
	return m_message.c_str();
}

axiom::range_exception::range_exception(operation_type opt_type, int32_t opt1, int32_t opt2,
	std::source_location location)
	: exception("opt: " + std::to_string(opt1) + "," + std::to_string(opt2), location),
	m_opt_type(opt_type), m_opt1(opt1), m_opt2(opt2)
{
}

axiom::operation_type axiom::range_exception::get_type() const
{
	return m_opt_type;
}
