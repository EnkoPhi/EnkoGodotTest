#include "ButtonScale.h"
#include <godot_cpp/classes/property_tweener.hpp>

void ButtonScale::_enter_tree()
{
    auto parentButton = Object::cast_to<Button>(get_parent());
    if (parentButton != nullptr)
    {
        _original_size = parentButton->get_scale();
        if (_from_center)
        {
            parentButton->set_pivot_offset(parentButton->get_size() / 2);
        }
        parentButton->connect("mouse_entered", callable_mp(this, &ButtonScale::_on_mouse_entered));
        parentButton->connect("mouse_exited", callable_mp(this, &ButtonScale::_on_mouse_exited));
        parentButton->connect("focus_entered", callable_mp(this, &ButtonScale::_on_mouse_entered));
        parentButton->connect("focus_exited", callable_mp(this, &ButtonScale::_on_mouse_exited));
    }
}

void ButtonScale::_exit_tree()
{
    auto parentButton = Object::cast_to<Button>(get_parent());
    if (parentButton != nullptr)
    {
        parentButton->disconnect("mouse_entered", callable_mp(this, &ButtonScale::_on_mouse_entered));
        parentButton->disconnect("mouse_exited", callable_mp(this, &ButtonScale::_on_mouse_exited));
        parentButton->disconnect("focus_entered", callable_mp(this, &ButtonScale::_on_mouse_entered));
        parentButton->disconnect("focus_exited", callable_mp(this, &ButtonScale::_on_mouse_exited));
    }
}

PackedStringArray ButtonScale::_get_configuration_warnings() const
{
    PackedStringArray warnings = Node::_get_configuration_warnings();
    Button *button = Object::cast_to<Button>(get_parent());
    if (button == nullptr)
    {
        warnings.push_back("ButtonAnimNode must be a child of a Button node.");
    }
    return warnings;
}

float ButtonScale::get_animation_duration() const
{
    return _animation_duration;
}

void ButtonScale::set_animation_duration(float p_duration)
{
    _animation_duration = p_duration;
}

Vector2 ButtonScale::get_scale() const
{
    return _scale;
}

void ButtonScale::set_scale(Vector2 p_scale)
{
    _scale = p_scale;
}

bool ButtonScale::get_from_center() const
{
    return _from_center;
}

void ButtonScale::set_from_center(bool p_from_ceneter)
{
    _from_center = p_from_ceneter;
}

bool ButtonScale::get_use_tween() const
{
    return _use_tween;
}

void ButtonScale::set_use_tween(bool p_use_tween)
{
    _use_tween = p_use_tween;
}

Tween::TransitionType ButtonScale::get_transition_type() const
{
    return _transition_type;
}

void ButtonScale::set_transition_type(Tween::TransitionType p_transition_type)
{
    _transition_type = p_transition_type;
}

Tween::EaseType ButtonScale::get_ease_type() const
{
    return _ease_type;
}

void ButtonScale::set_ease_type(Tween::EaseType p_ease_type)
{
    _ease_type = p_ease_type;
}

void ButtonScale::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("get_scale"), &ButtonScale::get_scale);
    ClassDB::bind_method(D_METHOD("set_scale", "scale"), &ButtonScale::set_scale);
    ClassDB::bind_method(D_METHOD("get_from_center"), &ButtonScale::get_from_center);
    ClassDB::bind_method(D_METHOD("set_from_center", "from_center"), &ButtonScale::set_from_center);
    ClassDB::bind_method(D_METHOD("get_use_tween"), &ButtonScale::get_use_tween);
    ClassDB::bind_method(D_METHOD("set_use_tween", "use_tween"), &ButtonScale::set_use_tween);
    ClassDB::bind_method(D_METHOD("get_animation_duration"), &ButtonScale::get_animation_duration);
    ClassDB::bind_method(D_METHOD("set_animation_duration", "duration"), &ButtonScale::set_animation_duration);
    ClassDB::bind_method(D_METHOD("get_transition_type"), &ButtonScale::get_transition_type);
    ClassDB::bind_method(D_METHOD("set_transition_type", "transition_type"), &ButtonScale::set_transition_type);
    ClassDB::bind_method(D_METHOD("get_ease_type"), &ButtonScale::get_ease_type);
    ClassDB::bind_method(D_METHOD("set_ease_type", "ease_type"), &ButtonScale::set_ease_type);

    ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "scale"), "set_scale", "get_scale");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "from_center"), "set_from_center", "get_from_center");
    ADD_GROUP("Tween", "");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "use_tween"), "set_use_tween", "get_use_tween");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "animation_duration"), "set_animation_duration", "get_animation_duration");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "transition_type", PROPERTY_HINT_ENUM, "Linear,Sine,Quint,Quart,Quad,Expo,Elastic,Cubic,Circ,Bounce,Back,Spring"), "set_transition_type", "get_transition_type");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "ease_type", PROPERTY_HINT_ENUM, "In,Out,InOut,OutIn"), "set_ease_type", "get_ease_type");
}

void ButtonScale::_on_mouse_entered()
{
    _scale_button(_scale);
}

void ButtonScale::_on_mouse_exited()
{
    _scale_button(_original_size);
}

void ButtonScale::_scale_button(Vector2 p_scale)
{
    auto parentButton = Object::cast_to<Button>(get_parent());
    if (nullptr == parentButton)
        return;

    if (_use_tween)
    {
        auto tween = create_tween();
        tween->tween_property(parentButton, "scale", p_scale, _animation_duration);
    }
    else
    {
        parentButton->set_scale(p_scale);
    }
}
