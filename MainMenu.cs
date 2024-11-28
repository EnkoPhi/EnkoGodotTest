using Godot;

namespace test;

public partial class MainMenu : Control
{
    [Export] public BaseButton newGameButton;
    [Export] public BaseButton loadGameButton;
    [Export] public BaseButton settingsButton;
    [Export] public BaseButton quitButton;

    public override void _Ready()
    {
        base._Ready();
        newGameButton.Pressed += OnNewGameButtonPressed;
        loadGameButton.Pressed += OnLoadGameButtonPressed;
        settingsButton.Pressed += OnSettingsButtonPressed;
        quitButton.Pressed += OnQuitButtonPressed;
    }

    public override void _ExitTree()
    {
        base._ExitTree();
        newGameButton.Pressed -= OnNewGameButtonPressed;
        loadGameButton.Pressed -= OnLoadGameButtonPressed;
        settingsButton.Pressed -= OnSettingsButtonPressed;
        quitButton.Pressed -= OnQuitButtonPressed;
    }

    private void OnNewGameButtonPressed()
    {
        // Load the game scene
        GetTree().ChangeSceneToFile("res://Game.tscn");
        // Destroy this
        QueueFree();
    }

    private void OnLoadGameButtonPressed()
    {
    }

    private void OnSettingsButtonPressed()
    {
    }

    private void OnQuitButtonPressed()
    {
        GetTree().Quit();
    }
}