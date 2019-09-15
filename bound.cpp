#include<graphics.h>
#include<iostream>
#include<stdio.h>
int boundary = 15;
int bfill(int,int,int);
int sfill(int,int,int);
int main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,NULL);
  setcolor(boundary);
  rectangle(50,50,350,350);
  sfill(60,60,15);
  getchar();
  closegraph();
}
int bfill(int x, int y, int color)
{
  int current = getpixel(x,y);
  if(current!=color && current!=boundary)
  {
    putpixel(x,y,color);
    bfill(x+1,y,color);
    bfill(x-1,y,color);
    bfill(x,y+1,color);
    bfill(x,y-1,color);
  }
}

int sfill(int x,int y, int color)
{
  int current = getpixel(x,y);
  if(current!=color)
  {
    putpixel(x,y,color);
    sfill(x+1,y,color);
    sfill(x-1,y,color);
    sfill(x,y+1,color);
    sfill(x,y-1,color);
  }
}
