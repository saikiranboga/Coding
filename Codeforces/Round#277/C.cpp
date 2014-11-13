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
    int n, p;
    cin >> n >> p;
    p--;
    string s;
    cin >> s;
    int chg_req[n];
    for(int i=0; i<n; i++)
        chg_req[i] = -1;
    int tot = 0;
    LL ans = 0;

    for(int i=0; i<n/2; i++){
        if(s[i]!=s[n-1-i]){
            int st = min( (int)(s[i]-'a'),(int)(s[n-1-i]-'a') );
            int ed = max( (int)(s[i]-'a'),(int)(s[n-1-i]-'a') );
            chg_req[i] = min( ed-st, st+26-ed );
            chg_req[n-1-i] = chg_req[i];
            tot++;
            ans += chg_req[i];
        }
    }

    int mn = -1, mx = -1;
    for(int i=0; i<n/2; i++){
        if(s[i]!=s[n-1-i]){
            mn = i;
            break;
        }
    }
    for(int i=0; i<n/2; i++){
        if(s[i]!=s[n-1-i])
            mx = i;
    }

    // cout << mn << " " << mx << endl;

    if(tot == 0){
        cout << 0 << endl;
    }
    else if(p < n/2){
        LL final_ans = ans + min(mx-mn, mn+n-mx) + min( abs(p-mn), abs(p-mx) );
        cout << final_ans << endl;
    }
    else{
        LL final_ans = ans + min(mx-mn, mn+n-mx) + min( abs(p-(n-1-mn)), abs(p-(n-1-mx)) );
        cout << final_ans << endl;
    }

    return 0;
}