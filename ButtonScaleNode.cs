using Godot;

namespace test;

public partial class ButtonScaleNode : Node
{
    [Export] public bool fromCenter = true;
    [Export] public Vector2 hoverScale = Vector2.One;
    [Export] public float scaleDuration = 0.5f;
    [Export] public Tween.TransitionType transitionType = Tween.TransitionType.Cubic;
    private Button _parentButton;
    private Vector2 _defaultScale;

    // Called when the node enters the scene tree for the first time.
    public override void _Ready()
    {
        var node = GetParent();
        if (node is not Button button)
        {
            GD.PushWarning("ButtonScaleNode must be a child of Button.");
            return;
        }

        _parentButton = button;
        _defaultScale = button.Scale;

        MakeConnection();
        CallDeferred("SetUp");
    }

    // Called every frame. 'delta' is the elapsed time since the previous frame.
    public override void _Process(double delta)
    {
    }

    public override void _ExitTree()
    {
        if (null == _parentButton) return;
        _parentButton.MouseEntered -= OnHover;
        _parentButton.MouseExited -= OffHover;
    }

    private void MakeConnection()
    {
        _parentButton.MouseEntered += OnHover;
        _parentButton.MouseExited += OffHover;
    }

    private void SetUp()
    {
        if (null == _parentButton) return;
        if (fromCenter)
        {
            _parentButton.PivotOffset = _parentButton.Size / 2;
        }
    }

    private void OnHover()
    {
        AddTween(hoverScale);
    }

    private void OffHover()
    {
        AddTween(_defaultScale);
    }

    private void AddTween(Vector2 scale)
    {
        var tween = CreateTween();
        tween.TweenProperty(_parentButton, "scale", scale, scaleDuration).SetTrans(transitionType);
    }
}