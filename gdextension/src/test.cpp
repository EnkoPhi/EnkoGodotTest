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

BitField<FLAGS> Test::get_flags()
{
    return flags;
}

void Test::set_flags(BitField<FLAGS> value)
{
    flags = value;
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

    ClassDB::bind_method(D_METHOD("get_flags"), &Test::get_flags);
    ClassDB::bind_method(D_METHOD("set_flags", "value"), &Test::set_flags);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "flags", PROPERTY_HINT_FLAGS, "Flag None,Flag 1,Flag 2,Flag 3,Flag 4"), "set_flags", "get_flags");

    BIND_ENUM_CONSTANT(TEST_ENUM_1);
    BIND_ENUM_CONSTANT(TEST_ENUM_2);
    BIND_ENUM_CONSTANT(TEST_ENUM_3);

    BIND_BITFIELD_FLAG(FLAG_NONE);
    BIND_BITFIELD_FLAG(FLAG_1);
    BIND_BITFIELD_FLAG(FLAG_2);
    BIND_BITFIELD_FLAG(FLAG_3);
    BIND_BITFIELD_FLAG(FLAG_4);

}
