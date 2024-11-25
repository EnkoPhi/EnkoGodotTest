#include "test.h"
#include <godot_cpp/variant/utility_functions.hpp>

void Test::start_test()
{
    UtilityFunctions::print("Hello from Test::start_test()");
}

int Test::get_testI()
{
    return testI;
}

void Test::set_testI(int value)
{
    testI = value;
}

float Test::get_testF()
{
    return testF;
}

void Test::set_testF(float value)
{
    testF = value;
}

String Test::get_testS()
{
    return testS;
}

void Test::set_testS(String value)
{
    testS = value;
}

Ref<ImageTexture> Test::get_testTexture()
{
    return testTexture;
}

void Test::set_testTexture(Ref<ImageTexture> value)
{
    testTexture = value;
}

void Test::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("start_test"), &Test::start_test);

    ClassDB::bind_method(D_METHOD("get_testI"), &Test::get_testI);
    ClassDB::bind_method(D_METHOD("set_testI", "value"), &Test::set_testI);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "testI"), "set_testI", "get_testI");

    ClassDB::bind_method(D_METHOD("get_testF"), &Test::get_testF);
    ClassDB::bind_method(D_METHOD("set_testF", "value"), &Test::set_testF);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "testF"), "set_testF", "get_testF");

    ClassDB::bind_method(D_METHOD("get_testS"), &Test::get_testS);
    ClassDB::bind_method(D_METHOD("set_testS", "value"), &Test::set_testS);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "testS"), "set_testS", "get_testS");

    ClassDB::bind_method(D_METHOD("get_testTexture"), &Test::get_testTexture);
    ClassDB::bind_method(D_METHOD("set_testTexture", "value"), &Test::set_testTexture);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "testTexture", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_testTexture", "get_testTexture");
}
