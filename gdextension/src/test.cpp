#include "test.h"
#include <godot_cpp/variant/utility_functions.hpp>

void Test::_ready()
{
    UtilityFunctions::print("Hello from Test::_ready()");
}
