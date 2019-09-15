#include<iostream>
#include<graphics.h>
#include<stdio.h>
using namespace std;
int main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,NULL);
  int x[4][4] = {{200,160,240,200},{200,240,240,200},{200,240,160,200},{200,160,160,200}};
  int y[4][4] = {{200,160,160,200},{200,160,240,200},{200,240,240,200},{200,240,160,200}};

  for(int i = 0; i<4; i++)
  {
    for(double t=0; t<1; t+=0.005)
    {
      double xt = pow(t,3)*x[i][3]+3*pow(t,2)*(1-t)*x[i][2]+3*pow((1-t),2)*t*x[i][1]+pow((1-t),3)*x[i][0];
      double yt = pow(t,3)*y[i][3]+3*pow(t,2)*(1-t)*y[i][2]+3*pow((1-t),2)*t*y[i][1]+pow((1-t),3)*y[i][0];
      putpixel(xt,yt,YELLOW);
      delay(5);
    }
  }
  getchar();
  closegraph();
}
