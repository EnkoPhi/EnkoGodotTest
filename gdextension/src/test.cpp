#include "test.h"
#include <godot_cpp/variant/utility_functions.hpp>


void Test::start_test()
{
    UtilityFunctions::print("Hello from Test::start_test()");
}

void Test::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("start_test"), &Test::start_test);
}
