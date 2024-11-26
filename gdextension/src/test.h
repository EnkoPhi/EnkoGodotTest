#ifndef TEST_H
#define TEST_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/image_texture.hpp>

using namespace godot;


class Test : public Node3D
{
    GDCLASS(Test, Node3D);

public:
    void start();
protected:
    static void _bind_methods();
};

#endif // TEST_H