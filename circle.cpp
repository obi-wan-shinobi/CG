#include<graphics.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
  int gd=DETECT, gm;
  initgraph(&gd,&gm,NULL);
  int x,y,r;
  cout<<"Enter centre and radius";
  cin>>x>>y>>r;
  int x1,y1;
  float p;
  x1=0; y1=r;
  //p=1-r;
  p=3-2*r;
  while(x1<y1)
  {
    if(p<=0)
    {
      x1++;
      p=p+4*x1+6;
      //p= p+2*x1+1;
    }
    else
    {
      x1++;
      y1--;
      p=p+4*(x1-y1)+10;
      //p= p+ 2*(x1-y1)+1;
    }
    putpixel(x+x1,y+y1,WHITE);
    putpixel(x+x1,y-y1,WHITE);
    putpixel(x-x1,y+y1,WHITE);
    putpixel(x-x1,y-y1,WHITE);
    putpixel(x+y1,y+x1,WHITE);
    putpixel(x+y1,y-x1,WHITE);
    putpixel(x-y1,y+x1,WHITE);
    putpixel(x-y1,y-x1,WHITE);
    delay(30);
  }
  delay(4000);
}
