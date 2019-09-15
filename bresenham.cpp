#include<iostream>
#include<graphics.h>
#include<stdio.h>
using namespace std;
bool bresenham(int,int,int,int);
int sign(int);
int main()
{
  int x1,x2,y1,y2;
  cout<<"Enter x1,y1,x2,y2:\n";
  cin>>x1>>y1>>x2>>y2;
  int gd = DETECT,gm;
  bool exg = false;
  initgraph(&gd,&gm,NULL);
  int dx,dy,sx,sy;
  int x,y;
  x=x1;
  y=y1;
  int p;
  dx=abs(x2-x1);
  dy=abs(y2-y1);
  sx=sign(x2-x1);
  sy=sign(y2-y1);
  p=2*dy-dx;
  if(dy>dx)
  {
    int temp=dy;
    dy=dx;
    dx=temp;
    x=y1;
    y=x1;
    exg = true;
  }
  int i=0;
  while(i<dx)
  {
    if(exg == false)
      putpixel(x,y,WHITE);
    else
      putpixel(y,x,WHITE);
    delay(10);
    x=x+sx;
    if(p<0)
    {
      p=p+2*dy;
    }
    else
    {
      y=y+sy;
      p=p+2*(dy-dx);
    }
    i++;
  }
  getchar();
  closegraph();
}
int sign(int arg)
{
  if(arg<0)
    return -1;
  else if(arg == 0)
    return 0;
  else
    return 1;
}
