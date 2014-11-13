#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

int number[1000010];

int main(){
    
    int n;
    cin >> n;
    int a[n];
    int cum[n+1];
    cum[0] = 0;
    int done_till = 0;

    for(int i=0; i<n; i++){
        
        cin >> a[i];
        // cum[i+1] = cum[i] + a[i];
        
        for(int j=done_till+1; j<=done_till+a[i]; j++)
            number[ j ] = i+1;
        done_till += a[i];
    }

    int q;
    cin >> q;
    int x;
    // for(int i=1; i<=done_till; i++)
    //     cout << number[i] << " ";
    // cout << endl;

    while(q--){
        cin >> x;
        // int up = upper_bound(cum+1, cum+n+1, x-1) - cum;
        // cout << up << endl;
        cout << number[x] << endl;
    }

    return 0;
}