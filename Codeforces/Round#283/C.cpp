#include <bits/stdc++.h>
using namespace std;

#define LL long long int

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<LL, LL>
#define all(v) (v.begin(), v.end())

#define MX 200010

int main(){
    int n,m;
    cin >> n >> m;
    string ar[n];
    for (int i = 0; i < n; ++i){
        cin >> ar[i];
    }
    if(n==1){
        cout << 0 << endl;
        return 0;
    }
    bool good = false;
    int row = -1, col = -1;
    int ans = 0;
    while(!good){
        good = true;
        for (int i = 0; i < n-1; ++i) {
            if(ar[i+1] < ar[i]){
                good = false;
                row = i;
                for (int j = 0; j < m; ++j) {
                    if(ar[i+1][j] < ar[i][j]){
                        col = j;
                        break;
                    }
                }
                break;
            }
        }
        if(!good) {
            ans++;
            for (int i = 0; i < n; ++i){
                ar[i].erase(ar[i].begin()+col);
                // cout << ar[i] << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}