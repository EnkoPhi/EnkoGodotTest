#ifndef TEST_H
#define TEST_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/image_texture.hpp>

using namespace godot;

class Test: public Node3D {
    GDCLASS(Test, Node3D);

public:
    void start_test();

    int get_testI();
    void set_testI(int value);

    float get_testF();
    void set_testF(float value);

    String get_testS();
    void set_testS(String value);

    Ref<ImageTexture> get_testTexture();
    void set_testTexture(Ref<ImageTexture> value);

protected:
    static void _bind_methods();

private:
    int testI = 0;
    float testF = 0.0f;
    String testS = "Hello, World!";
    Ref<ImageTexture> testTexture;
};

#endif // TEST_H