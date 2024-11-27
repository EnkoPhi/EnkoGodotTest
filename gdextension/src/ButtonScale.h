#ifndef BUTTON_SCALE_H
#define BUTTON_SCALE_H

#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/tween.hpp>

using namespace godot;

class ButtonScale : public Node
{
    GDCLASS(ButtonScale, Node);

public:
    void _enter_tree() override;
    void _exit_tree() override;

    PackedStringArray _get_configuration_warnings() const override;
    Vector2 get_scale() const;
    void set_scale(Vector2 p_scale);

    bool get_from_center() const;
    void set_from_center(bool p_from_center);

    bool get_use_tween() const;
    void set_use_tween(bool p_use_tween);

    float get_animation_duration() const;
    void set_animation_duration(float p_duration);

    Tween::TransitionType get_transition_type() const;
    void set_transition_type(Tween::TransitionType p_transition_type);

    Tween::EaseType get_ease_type() const;
    void set_ease_type(Tween::EaseType p_ease_type);

protected:
    static void _bind_methods();

private:
    void _on_mouse_entered();
    void _on_mouse_exited();
    void _scale_button(Vector2 p_scale);

    Vector2 _scale = Vector2(1.2, 1.2);
    bool _from_center = true;
    Vector2 _original_size = Vector2(1, 1);
    bool _use_tween = true;
    float _animation_duration = 0.5f;
    Tween::TransitionType _transition_type = Tween::TransitionType::TRANS_LINEAR;
    Tween::EaseType _ease_type = Tween::EaseType::EASE_OUT;
};

#endif // BUTTON_SCALE_H