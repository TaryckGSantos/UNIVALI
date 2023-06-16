using Godot;
using System;

public partial class Player : CharacterBody2D
{
  private AnimatedSprite2D animation;
  public const float Speed = 300.0f;
  public const float JumpVelocity = -400.0f;

  private int jump_count = 0;

  public Vector2 initialPosition;

  public Vector2 savepoint;

  public int qtd_coleta = 0;

  // Get the gravity from the project settings to be synced with RigidBody nodes.
  public float gravity = ProjectSettings.GetSetting("physics/2d/default_gravity").AsSingle();

  public override void _Ready()
  {
    animation = GetNode<AnimatedSprite2D>("AnimatedSprite2D");
    initialPosition = Position;
    savepoint = initialPosition;
  }

  public override void _PhysicsProcess(double delta)
  {
    Vector2 velocity = Velocity;

    // Add the gravity.
    if (!IsOnFloor())
    {
      velocity.Y += gravity * (float)delta;
    }

    // Handle Jump.
    if (Input.IsActionJustPressed("ui_accept"))
    {
      if (IsOnFloor())
      {
        velocity.Y = JumpVelocity;
        jump_count = 1;
      }
      else if (jump_count == 1)
      {
        velocity.Y = JumpVelocity + 100;
        jump_count = 0;
      }
    }

    // Get the input direction and handle the movement/deceleration.
    // As good practice, you should replace UI actions with custom gameplay actions.
    Vector2 direction = Input.GetVector("ui_left", "ui_right", "ui_up", "ui_down");
    if (direction != Vector2.Zero)
    {
      velocity.X = direction.X * Speed;
    }
    else
    {
      velocity.X = Mathf.MoveToward(Velocity.X, 0, Speed);
    }

    Velocity = velocity;

    if (!IsOnFloor())
    {
      animation.Play("jump");
    }
    else
    {
      if (velocity.X != 0)
      {
        animation.Play("run");
        if (velocity.X > 0)
        {
          animation.FlipH = true;
        }
        else
        {
          animation.FlipH = false;
        }
      }
      else
      {
        animation.Play("idle");
      }
    }

    if (GlobalPosition.Y > 900)
    {
      Position = GetSavePoint();
    }
    MoveAndSlide();
  }


  public void ReturnToSavePoint()
  {
    GlobalPosition = savepoint;
  }

  public void setSavePoint(Vector2 checkpoint)
  {
    savepoint = checkpoint;
  }

  public Vector2 GetSavePoint()
  {
    return this.savepoint;
  }

  public void setColeta()
  {
      this.qtd_coleta++;
      if(this.qtd_coleta>=3){
        GD.Print("Parabéns! Jogo Encerrado!");
      } 
  }

  public int getColeta()
  {
      return this.qtd_coleta++; 
  }
}

