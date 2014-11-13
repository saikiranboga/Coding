#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

class Point{
 public:
  double x;
  double y;
  Point(){
  }
  Point(double _x, double _y){
    x = _x;
    y = _y;
  }
  double dist(Point *p){
    double temp = x - p->x;
    temp *= temp;
    double ret = temp;
    temp = y - p->y;
    temp *= temp;
    ret += temp;
    return sqrt(ret);
  }
};

double calcArea(Point *p1, Point *p2, Point *p3){
  double a = p1->dist(p2);
  double b = p2->dist(p3);
  double c = p3->dist(p1);
  double s = (a+b+c)/2.0;
  double temp = s*(s-a)*(s-b)*(s-c);
  return sqrt(temp);
}

int main(){
  int i,n;
  cin >> n;
  double min_area = INT_MAX;
  double max_area = -1;
  int min_idx = 1,max_idx = 1;

  Point *p1 = new Point();
  Point *p2 = new Point();
  Point *p3 = new Point();
  double area;
  for(i=1;i<=n;i++){    
    cin >> p1->x >> p1->y;
    cin >> p2->x >> p2->y;
    cin >> p3->x >> p3->y;
    area = calcArea(p1, p2, p3);
    if(area <= min_area){
      min_idx = i;
      min_area = area;
    }
    if(area >= max_area){
      max_idx = i;
      max_area = area;
    }
  }
  cout << min_idx << " " << max_idx << endl;
  return 0;
}
