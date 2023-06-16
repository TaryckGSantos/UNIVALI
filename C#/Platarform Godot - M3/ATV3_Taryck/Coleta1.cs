using Godot;
using System;

public partial class Coleta1 : Area2D
{
	// Called when the node enters the scene tree for the first time.
	public override void _Ready()
	{
	}

	// Called every frame. 'delta' is the elapsed time since the previous frame.
	public override void _Process(double delta)
	{
	}

	private void OnBodyEntered(Node2D body)
	{
		if (body is Player)
		{
			Player playerInstance = (Player)body;
        	QueueFree();
        	GD.Print("Moeda coletada!");
			playerInstance.setColeta();
		}
	}
}
