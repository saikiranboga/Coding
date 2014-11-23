#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define LL long long int

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

int main(){
    int hy, ay, dy;
    int hm, am, dm;
    int h, a, d;
    cin >> hy >> ay >> dy;
    cin >> hm >> am >> dm;
    cin >> h >> a >> d;
    int minm = 1000000;
    for(int hp=0; hp<110; hp++){
        for(int at=0; at<110; at++){
            for(int df=0; df<110; df++){
                if(max(0,ay+at-dm)==0 ){
                    continue;
                }
                if(max(0,am-dy-df)==0){
                    if(hp*h + at*a + df*d < minm){
                        minm = hp*h + at*a + df*d;
                        cout << hp << " " << at << " " << df << endl;
                    }
                    continue;
                }
                int yrem = (hy+hp) - ceil((float)(hy+hp)/(float)(am-dy-df))*(am-dy-df);
                int mrem = hm - ceil((float)hm/(float)(ay+at-dm))*(ay+at-dm);
                if( yrem > mrem && (hy+hp)/(am-dy-df) > hm/(ay+at-dm) ){
                    if(hp*h + at*a + df*d < minm){
                        minm = hp*h + at*a + df*d;
                        cout << hp << " " << at << " " << df << endl;
                    }
                }
            }
        }
    }
    cout << minm << endl;
    return 0;
}
/*
1 2 1
1 100 1
1 100 100
*/