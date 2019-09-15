#include<iostream>
#include<graphics.h>
#include<stdio.h>
using namespace std;
void draw_poly(int [],int [],int);
void scanline(int [],int [], int);
int main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,NULL);
  setcolor(WHITE);
  int *x,*y,n;
  cout<<"Enter number of vertices:\t";
  cin>>n;
  x = new int[n];
  y = new int[n];

  cout<<"Enter x and y coordinates:\n";
  for(int i=0;i<n;i++)
  {
    cin>>x[i]>>y[i];
  }
  draw_poly(x,y,n);
  scanline(x,y,n);
  getchar();
  closegraph();
}
void draw_poly(int x[], int y[],int n)
{
  for(int i=0; i<n-1; i++)
  {
    line(x[i],y[i],x[i+1],y[i+1]);
  }
  line(x[n-1],y[n-1],x[0],y[0]);
}
void scanline(int x[], int y[], int n)
{
  
}
