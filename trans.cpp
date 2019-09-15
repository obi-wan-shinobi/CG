#include<iostream>
#include<stdio.h>
#include<graphics.h>
using namespace std;
int **multiply(int **,int [3][3], int);
void draw_poly(int**,int);
int main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,NULL);
  setcolor(WHITE);
  int **poly,n;
  cout<<"Enter number of vertices:\t";
  cin>>n;
  poly = new int *[n];
  for(int i=0; i<n; i++)
    poly[i] = new int[3];

  cout<<"Enter x and y coordinates:\n";
  for(int i=0;i<n;i++)
  {
    cin>>poly[i][0]>>poly[i][1];
    poly[i][2] = 1;
  }

  int translate[3][3],rotate[3][3],scale[3][3],shear[3][3];
  int tx,ty,sx,sy,shrx,shry;
  float theta;
  //translate
/*  cout<<"Enter translate:";
  cin>>tx>>ty;*/
  for(int i=0; i<3;i++)
    for(int j=0; j<3; j++)
    {
      if(i==j)
        translate[i][j]=1;
      else
        translate[i][j]=0;
    }
  //translate[2][0]=tx;
  //translate[2][1]=ty;
  //int **new_poly = multiply(poly,translate,n);
  //Scale
/*  cout<<"Enter Scale:";
  cin>>sx;
  cout<<"Enter scale:";
  cin>>sy;
  for(int i=0; i<3;i++)
    for(int j=0; j<3; j++)
    {
      if(i==j)
        scale[i][j]=1;
      else
        scale[i][j]=0;
    }
  scale[0][0]=sx;
  scale[1][1]=sy;
*/
  int **new_sc = multiply(poly,scale,n);
  //Rotate
  cout<<"Enter Angle:";
  cin>>theta;
  tx=poly[0][0];
	ty=poly[0][1];
  float angle = theta*M_PI/180;
  for(int i=0; i<3;i++)
    for(int j=0; j<3; j++)
    {
      if(i==j)
        rotate[i][j]=1;
      else
        rotate[i][j]=0;
    }
  rotate[0][0]=cos(angle);
  rotate[0][1]=sin(angle);
  rotate[1][0]=-sin(angle);
  rotate[1][1]=cos(angle);
  rotate[2][0]=ty*sin(angle)+tx*(1-cos(angle));
  rotate[2][1]=(-tx)*sin(angle)+ty*(1-cos(angle));

  int **new_rt = multiply(poly,rotate,n);

/*  //Shear
 cout<<"Enter shear:\n";
  cin>>shrx>>shry;
  for(int i=0; i<3;i++)
    for(int j=0; j<3; j++)
    {
      if(i==j)
        shear[i][j]=1;
      else
        shear[i][j]=0;
    }
  shear[0][1]=shrx;
  shear[1][0]=shry;
  int **new_shr = multiply(poly,shear,n);
*/
  draw_poly(poly,n);
  delay(4000);
  //getchar();
  cleardevice();
/*  draw_poly(new_poly,n);
  delay(4000);
  cleardevice();
  draw_poly(new_sc,n);
  delay(4000);
  cleardevice();*/
  draw_poly(new_rt,n);
  delay(1000);
  /*cleardevice();
  draw_poly(new_shr,n);
  delay(4000);*/
  //getchar();  closegraph();
}
void draw_poly(int **poly,int n)
{
  for(int i=0; i<n-1; i++)
  {
    line(poly[i][0],poly[i][1],poly[i+1][0],poly[i+1][1]);
  }
  line(poly[n-1][0],poly[n-1][1],poly[0][0],poly[0][1]);
}
int **multiply(int **a, int b[][3], int n)
{
  int **res;
  res = new int*[n];
  for(int i=0; i<n; i++)
  {
    res[i] = new int[3];
    for(int j=0; j<3; j++)
    {
      res[i][j]=0;
      for(int k=0; k<3; k++)
        res[i][j]+=a[i][k]*b[k][j];
    }
  }
  return res;
}
