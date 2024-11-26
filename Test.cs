using Godot;

namespace test;

public partial class Test : Node
{
	[Export]
	public Node3D node;

	public override void _Ready()
	{
		GD.Print("Hello, world from csharp!");
		GD.Print(node);
		node.Position += new Vector3(1, 1, 1);
	}
}
