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
    
    int cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;

    int up1, up2, tot1, tot2;
    tot1 = cnt1/(x-1);
    tot2 = cnt2/(y-1);
    
    if(cnt1%x-1 == 0)
        up1 = x*tot1-1;
    else
        up1 = x*tot1+(cnt1%x-1);

    if(cnt2%(y-1) == 0)
        up2 = y*tot2-1;
    else
        up2 = y*tot2+(cnt2%(y-1));

    int ans = max(up1, up2);
    cout << ans << endl;
    return 0;
}