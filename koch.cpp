#include<iostream>
#include<stdio.h>
#include<graphics.h>
using namespace std;
void koch(int,int,int,int,int);
int main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,NULL);
  cout<<"Enter the co-ordinates of line\t";
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  koch(x1,y1,x2,y2,10);
  getchar();
  closegraph();
}
void koch(int x1,int y1, int x2,int y2, int it)
{
  float theta = M_PI*60/180;
  int x3,y3,x4,y4;
  x3=(2*x1+x2)/3;
  y3=(2*y1+y2)/3;
  x4=(2*x2+x1)/3;
  y4=(2*y2+y1)/3;

  int x,y;
  x=x3+(x4-x3)*cos(theta)+(y4-y3)*sin(theta);
  y=y3-(x4-x3)*sin(theta)+(y4-y3)*cos(theta);

  if(it>0)
  {
    koch(x1,y1,x3,y3,it-1);
    koch(x3,y3,x,y,it-1);
    koch(x,y,x4,y4,it-1);
    koch(x4,y4,x2,y2,it-1);
  }
  else
  {
    line(x1,y1,x3,y3);
    line(x3,y3,x,y);
    line(x,y,x4,y4);
    line(x4,y4,x2,y2);
  }
}
