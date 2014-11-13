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
    LL balls[3];
    for(int i=0; i<3; i++)
        cin >> balls[i];
    sort(balls, balls+3);
    if( balls[2] >= 2*(balls[0]+balls[1]) ){
        LL ans = balls[0] + balls[1];
        cout << ans << endl;
    }
    else{
        LL ans = ( balls[0] + balls[1] + balls[2] )/3;
        cout << ans << endl;
    }
}