#include<iostream>
#include<stdio.h>
#include<graphics.h>
using namespace std;

static int A=8,B=4,R=2,L=1,xl,yl,xh,yh;

int getcode(int x,int y)
{
  int code = 0;
  if(y<yl)
    code |= B;
  if(y>yh)
    code |= A;
  if(x<xl)
    code |= L;
  if(x>xh)
    code |= R;

  return code;
}
int main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,NULL);

  setcolor(BLUE);

  xl=200; xh=440;
  yl=180; yh=300;

  rectangle(xl,yl,xh,yh);

  int x1,y1,x2,y2;

  x1=250; y1 = 200;
  x2=400; y2 = 350;

  line(x1,y1,x2,y2);
  int outcode1,outcode2;
  outcode1=getcode(x1,y1);
  outcode2=getcode(x2,y2);
  int accept = 0;

  while(true)
  {
    float m = (float)(y2-y1)/(x2-x1);
    if(outcode1==0 && outcode2==0)
    {
      accept = 1;
      break;
    }
    else if((outcode1 & outcode2) != 0)
      break;
    else
    {
      int x,y,temp;
      if(outcode1==0)
        temp = outcode2;
      else
        temp = outcode1;
      if(temp & A)
      {
        y=yh;
        x= x1+(yh-y1)/m;
      }
      if(temp & B)
      {
        y=yl;
        x=x1+(yl-y1)/m;
      }
      if(temp & R)
      {
        x=xh;
        y=y1+m*(xh-x1);
      }
      if(temp & L)
      {
        x=xl;
        y=y1+m*(xl-x1);
      }

      if(temp == outcode1)
      {
        x1 = x;
        y1 = y;
        outcode1=getcode(x1,y1);
      }
      else
      {
        x2 = x;
        y2 = y;
        outcode2=getcode(x2,y2);
      }
    }
  }
  setcolor(WHITE);
  if(accept==1)
    line(x1,y1,x2,y2);
  getch();
  closegraph();
}
