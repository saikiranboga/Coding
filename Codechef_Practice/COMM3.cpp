#include <iostream>
#include <cmath>
using namespace std;

struct point{
  int x;
  int y;
};

int main(){
  int t;
  cin >> t;
  while(t--){
    point a,b,c;
    double d;
    cin >> d;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    float d_x, d_y, d1, d2, d3;

    d_x = a.x-b.x;
    d_x *= d_x;

    d_y = a.y-b.y;
    d_y *= d_y;

    d1 = sqrt(d_x + d_y);

    d_x = b.x-c.x;
    d_x *= d_x;

    d_y = b.y-c.y;
    d_y *= d_y;

    d2 = sqrt(d_x + d_y);

    d_x = c.x-a.x;
    d_x *= d_x;

    d_y = c.y-a.y;
    d_y *= d_y;

    d3 = sqrt(d_x + d_y);

    int count=0;
    if(d1 <= d)
      count++;
    if(d2 <= d)
      count++;
    if(d3 <= d)
      count++;
    if(count > 1)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}
