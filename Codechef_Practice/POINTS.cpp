#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

struct Node{
  int x;
  int y;
}points[100001];

bool compare(const Node& a, const Node& b){
  if( (a.x - b.x) < 0)
    return true;
  else if( ( a.x - b.x) > 0)
    return false;
  else if( ( a.y - b.y) < 0)
    return false;
  else
    return true;
}

int main(){
  int t,n,i;
  cin >> t;
  while(t--){
    cin >> n;
    for(i=0;i<n;i++)
      cin >> points[i].x >> points[i].y;
    sort(points,points+n,&compare);

    double ans = 0;
    double x_d,y_d,d;
    n--;
    for(i=0;i<n;i++){
      x_d = (points[i].x-points[i+1].x);
      x_d *= x_d;

      y_d = (points[i].y-points[i+1].y);
      y_d *= y_d;

      d = sqrt(x_d + y_d);

      ans += d;
    }

    ans = round(ans*100.0);
    ans = ans/100.0;

    //    cout << set_precision(2) << ans << endl;
    printf("%.2lf\n",ans);

  }
  return 0;
}
