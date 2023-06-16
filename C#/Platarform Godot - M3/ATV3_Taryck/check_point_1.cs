using Godot;
using System;

public partial class check_point_1 : Area2D
{
  public override void _Ready()
  {
  }

  public override void _Process(double delta)
  {
  }

  public void OnBodyEntered(Node2D body)
  {

    if (body is Player)
    {
      ((Player)body).setSavePoint(Position - new Vector2(0, 6));
      GD.Print("Caminho salvo!");
    }
  }
}
