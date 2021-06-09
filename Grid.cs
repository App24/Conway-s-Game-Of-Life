using System;
using SFML.Graphics;

namespace GOL{
    public class Grid {
        public int GridSize{get;}

        bool[] grid;

        public Image GridImage{get;private set;}
        public Texture GridTexture{get;private set;}

        float threashold;

        public Grid(int gridSize, float threashold){
            GridSize=gridSize;
            GridImage=new Image((uint)gridSize, (uint)gridSize);
            grid=new bool[gridSize*gridSize];
            GridTexture=new Texture(GridImage);
            this.threashold=threashold;
            Reset();
        }

        public void Reset(){
            Random rand=new Random();
            for(int i=0;i<grid.Length;i++){
                grid[i]=rand.Next(101)/100f>threashold;
            }
        }

        public void Update(){
            bool[] tempGrid=(bool[])grid.Clone();

            for(int y=0;y<GridSize;y++){
                for(int x=0;x<GridSize;x++){
                    int res=0;

                    int xx0=x-1;
                    int yy0=y-1;
                    int xx1=x+1;
                    int yy1=y+1;

                    if(x!=0)
                        res+=tempGrid[xx0+GridSize*y]?1:0;

                    if(y!=0)
                        res+=tempGrid[x+GridSize*yy0]?1:0;

                    if(x!=GridSize-1)
                        res+=tempGrid[xx1+GridSize*y]?1:0;

                    if(y!=GridSize-1)
                        res+=tempGrid[x+GridSize*yy1]?1:0;

                    if(x!=0 && y!=0)
                        res+=tempGrid[xx0+GridSize*yy0]?1:0;

                    if(x!=GridSize-1 && y!=0)
                        res+=tempGrid[xx1+GridSize*yy0]?1:0;

                    if(x!=0 && y!=GridSize-1)
                        res+=tempGrid[xx0+GridSize*yy1]?1:0;

                    if(x!=GridSize-1 && y!=GridSize-1)
                        res+=tempGrid[xx1+GridSize*yy1]?1:0;

                    if(!(tempGrid[x+GridSize*y]&&(res==3||res==2)))
                        grid[x+GridSize*y]=false;
                    if(!tempGrid[x+GridSize*y] && res==3)
                        grid[x+GridSize*y]=true;
                }
            }

            for(uint x=0;x<GridImage.Size.X;x++){
                for(uint y=0;y<GridImage.Size.Y;y++){
                    GridImage.SetPixel(x,y, grid[y*GridImage.Size.X+x]?Color.White:Color.Black);
                }
            }
            GridTexture.Update(GridImage);
        }
    }
}