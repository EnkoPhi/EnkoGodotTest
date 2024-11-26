#include "test.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/timer.hpp>

void Test::start()
{
    auto childCount = get_child_count();
    if (childCount < 1)
    {
        UtilityFunctions::print("No child found");
        return;
    }
    auto child = get_child(0);
    if(child->is_class("Timer")){
        auto timer = Object::cast_to<Timer>(child);
        UtilityFunctions::print("Timer found", timer);
    }else{
        UtilityFunctions::print("First Child is not a Timer");
    }
}

void Test::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("start"), &Test::start);
}
