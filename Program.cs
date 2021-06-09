using System;
using SFML.Graphics;
using SFML.System;
using GOL.Systems;
using GOL.Input;

namespace GOL
{
    class Program
    {
        static void Main(string[] args)
        {
            DisplayManager.InitialiseDisplay(600,600, "Conway's Game Of Life");

            AssetLoader.LoadAssets();

            int generationSpeed=60;

            Clock clock=new Clock();

            Grid grid=new Grid(200, 0.8f);
            
            Sprite sprite=new Sprite(grid.GridTexture);

            sprite.Scale=new SFML.System.Vector2f(DisplayManager.Width/(float)grid.GridImage.Size.X, DisplayManager.Height/(float)grid.GridImage.Size.Y);

            Text speedText=new Text(generationSpeed.ToString(), AssetManager.GetFont("arial"), 16);

            while(DisplayManager.Window.IsOpen){
                DisplayManager.Window.DispatchEvents();

                if(clock.ElapsedTime.AsMilliseconds()>=(1000/(float)generationSpeed)){
                    clock.Restart();
                    grid.Update();
                }

                if(KeyboardInput.IsKeyPressed(SFML.Window.Keyboard.Key.R)){
                    grid.Reset();
                }

                if(KeyboardInput.IsKeyPressed(SFML.Window.Keyboard.Key.Down)){
                    generationSpeed-=5;
                    if(generationSpeed<10) generationSpeed=10;
                    speedText.DisplayedString=generationSpeed.ToString();
                }else if(KeyboardInput.IsKeyPressed(SFML.Window.Keyboard.Key.Up)){
                    generationSpeed+=5;
                    speedText.DisplayedString=generationSpeed.ToString();
                }

                DisplayManager.Window.Clear();

                DisplayManager.Window.Draw(sprite);
                DisplayManager.Window.Draw(speedText);

                DisplayManager.Window.Display();
                KeyboardInput.ResetKeyboard();
            }
        }
    }
}
