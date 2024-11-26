#include "test.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/timer.hpp>

void Test::start()
{
    auto children = get_children();
    for (auto i = 0; i < children.size(); i++)
    {
        auto child = children[i];
        auto timer = Object::cast_to<Timer>(child);
        if (timer)
        {
            UtilityFunctions::prints("Timer found, the index is ", i);
        }
    }
}

void Test::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("start"), &Test::start);
}
