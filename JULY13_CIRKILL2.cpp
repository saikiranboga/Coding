#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
 
# define FOR(i, a, b) for (int i=a; i<b; i++)
# define REP(i, a) FOR(i,0,a)
 
#define EPS 1e-11
#define inf 1234567891
#define LL long long
 
#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))
 
# define VI vector<int>
# define VS vector<string>
# define VC vector<char>
 
#define mp make_pair
#define pb push_back
#define sz(k) (int)(k).size()
#define FORIT(i,m) for(__typeof((m).begin()) i=(m).begin();i!=(m).end();i++)
#define pii pair<int,int>
#define UNIQUE(c) (c).resize( unique( all(c) ) - (c).begin() )
 
#define READ(f) {ifstream infile(f) ;if(infile.good()) freopen(f, "r", stdin);}
#define WRITE(f) freopen(f, "w", stdout)
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
 
using namespace std;
 
template <class stl>
void DBGSTL (stl a) { // for deque, vector , set
    FORIT(i,a) {
        cerr<<*i<<" ";
    }
    cerr<<"\n";
    return;
}
 
double eps = 1e-8;
struct point2d {
    double x,y;
 
    point2d() {
        x=y=0;
    }
    point2d(double _x , double _y) {
        x= _x;
        y= _y;
    }
    point2d operator+(point2d v) {
        return point2d (x+v.x, y+v.y);
    }
};
struct Line {
    double A,B,C;
};//Ax + By = C
Line makeline(point2d a1, point2d a2) {
    Line ret = (Line) {
        a2.y-a1.y, a1.x-a2.x
    };
    ret.C = ret.A * a1.x + ret.B * a1.y;
    return ret;
}
Line rot90(Line l, point2d p) {
    Line ret = (Line) {
        -l.B, l.A
    };
    ret.C = ret.A * p.x + ret.B * p.y;
    return ret;
}
pair <bool , point2d > intersect(Line l1, Line l2) {
    double det = l1.A*l2.B - l2.A*l1.B;
    if(fabs(det) < eps) {
        det=0;//zero means parallel
        pair <bool , point2d >(0, point2d((l2.B*l1.C - l1.B*l2.C)/det, (l1.A*l2.C - l2.A*l1.C)/det));
    }
    return pair <bool , point2d >(1, point2d((l2.B*l1.C - l1.B*l2.C)/det, (l1.A*l2.C - l2.A*l1.C)/det));
}
 
// get a line passing between two points
Line getmidline(point2d a, point2d b) {
    point2d mid(a+b);
    mid.x/=2;
    mid.y/=2;
    return rot90( makeline(a,b), mid );
}
 
 
double dist(point2d a ,point2d b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y - b.y)*(a.y - b.y));
}
vector <point2d> v;
 
bool eq(double a, double b){
    if(fabs(a-b) > EPS) return 0;
    return 1;
}
 
pair <bool , point2d > can(point2d a, point2d b , point2d c) {
    Line l1 = getmidline(a,b);
    Line l2 = getmidline(b,c);
    pair <bool , point2d > center = intersect(l1,l2);
    if(center.first ==0 ){
        return center;
    }
    double dist1 = dist(a, center.second);
    double dist2 = dist(b, center.second);
    double dist3 = dist(c, center.second);
 
    if(eq(dist1, dist2) && eq(dist2, dist3)){
        return pair <bool, point2d> (1, center.second);
    }
    return pair <bool, point2d> (0, center.second);
}
bool colinear(int x1, int y1, int x2, int y2, int x3, int y3) {
  return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2);
}
 
int main() {
    int n,t;
    double x, y;
    cin>>t;
    while(t--) {
        v.clear();
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>x>>y;
            v.pb(point2d(x,y));
        }
        int place =  0;
        int happen = 0;
        for(int i=0; i<v.size(); i++) {
            for(int j=i+1; j<v.size(); j++) {
                for(int k=j+1; k<v.size(); k++) {
                    place++;
                    if(colinear(v[i].x, v[i].y, v[j].x, v[j].y, v[k].x, v[k].y)){
                        continue;
                    }
                    pair <bool, point2d > ret = can(v[i],v[j],v[k]);
                    if(ret.first){
                        double r = dist(v[i],ret.second);
                        for(int l=0;l<v.size();l++){
                            if(l==i || l==j || l==k) continue;
 
                            double d = dist(ret.second, v[l]);
                            if( (d<r) || (fabs(d-r) <= 0.000001) ){
                                happen++;
                            }
                        }
                    }
                }
            }
        }
        double res= (1.0 * happen ) / (1.0 * (n-3) * place);
        printf("%.15lf\n",res);
    }
    return 0;
}
