#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef struct Point
{
  double x;
  double y;
}Point;

double dist(Point A, Point B)
{
  cout << "here\n";
  double ret;
  double temp = (A.x - B.x);
  temp *= temp;
  ret = temp;
  temp = (A.y - B.y);
  temp *= temp;
  ret += temp;
  return sqrt(abs(ret));
}

int main()
{
  int N;
  int s_no;
  Point city[40];
	
  scanf("%d",&N);
  int i,j;
  double x,y;
  for(i=0; i<N; i++)
    {
      cin >> s_no >> x >> y;
      city[i].x = x;
      city[i].y = y;
      cout << city[i].x << " " << city[i].y << "\n";
    }
  Point a, b;
  for(i=0; i<N; i++)
    {
      for(j=0; j<N; j++)
	{
	  cout << i << j << endl;
	  if(i==j)
	    cout << "0 ";
	  else{
	    a = city[i];
	    b = city[j];
	    x = dist(a,b);
	    cout << x << " ";
	  }
	}
      cout << "\n";
    }
  return 0;
}
