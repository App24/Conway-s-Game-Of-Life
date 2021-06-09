using System;
using SFML.Graphics;
using SFML.Window;
using SFML.System;
using GOL.Input;

namespace GOL.Systems{
    public static class DisplayManager {
        public static RenderWindow Window{get;private set;}

        public static uint Width{get{return Window.Size.X;}}
        public static uint Height{get{return Window.Size.Y;}}

        public static void InitialiseDisplay(uint width, uint height, string title){
            Window=new RenderWindow(new VideoMode(width, height), title, Styles.Close|Styles.Titlebar);
            Window.Closed+=new EventHandler((_,__)=>Close());
            Window.KeyPressed+=KeyboardInput.KeyPressed;
            Window.KeyReleased+=KeyboardInput.KeyReleased;
        }

        public static void Close(){
            Window.Close();
        }
    }
}