#include<iostream>
using namespace std;
int ***arr();
int main()
{
  int ***a;
  a=arr();
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
      for(int k=0; k<3; k++)
        cout<<a[i][j][k];
}
int ***arr()
{
  int ***a;
  a = new int**[3];
  for(int i=0; i<3; i++)
  {
    a[i] = new int*[3];
    for(int j=0; j<3; j++)
    {
      a[i][j] = new int[3];
      for(int k=0; k<3; k++)
        a[i][j][k]=1;
    }
  }
  return a;
}
