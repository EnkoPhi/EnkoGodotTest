#ifndef TEST_H
#define TEST_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/image_texture.hpp>

using namespace godot;

enum TestEnum
{
    TEST_ENUM_1 = 0,
    TEST_ENUM_2 = 5,
    TEST_ENUM_3 = 10
};

enum FLAGS
{
    FLAG_NONE = 0,
    FLAG_1 = 1,
    FLAG_2 = 1 << 1,
    FLAG_3 = 1 << 2,
    FLAG_4 = 1 << 3,
};

class Test : public Node3D
{
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

    BitField<FLAGS> get_flags();
    void set_flags(BitField<FLAGS> value);

protected:
    static void _bind_methods();

private:
    int testI = 0;
    float testF = 0.0f;
    String testS = "Hello, World!";
    Ref<ImageTexture> testTexture;
    BitField<FLAGS> flags = FLAG_NONE;
};

VARIANT_ENUM_CAST(TestEnum);
VARIANT_BITFIELD_CAST(FLAGS);

#endif // TEST_H