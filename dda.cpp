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
  int startx,starty;
  float p;
  x1=0; y1=r;
  startx=x1;
  starty=y1;
  int arr[10]={1,2,4,8,16,32,64,128,256,512};
  int i=0;
  while(r<arr[i])
    i++;

  double ep = 1/arr[i];
  //p=1-r;
  while(y1-starty < ep || startx-x1 > ep)
  {
    int x2,y2;
    x2=x1+ep*y1;
    y2=y1-ep*x2;
    putpixel(x2+x,y2+y,WHITE);
    x1=x2;
    y1=y2;
  }
  delay(4000);
}
