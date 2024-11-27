using Godot;

namespace test;

public partial class ButtonAnim : Button
{
    [Export] public float intensity = 1.1f;
    [Export] public float duration = 0.5f;

    // Called when the node enters the scene tree for the first time.
    public override void _Ready()
    {
    }

    // Called every frame. 'delta' is the elapsed time since the previous frame.
    public override void _Process(double delta)
    {
    }
}