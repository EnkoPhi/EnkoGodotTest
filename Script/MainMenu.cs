using Godot;
using test.Script.Core;

namespace test.Script;

public partial class MainMenu : WindowBase
{
    [Export] public BaseButton newGameButton;
    [Export] public BaseButton loadGameButton;
    [Export] public BaseButton settingsButton;
    [Export] public BaseButton quitButton;
    [Export] public PackedScene gameScene;

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
        GetTree().ChangeSceneToPacked(gameScene);
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