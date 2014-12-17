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
    int l;
    cin >> l;
    string inp;
    cin >> inp;
    vector<string> posb;
    for (int j = 0; j < 10 ; ++j) {
        string dup = inp;
        for (int i = 0; i < l; ++i)
            dup[i] = (char)( ((int)(dup[i]-'0') + j)%10 + '0');
        // cout << dup << endl;
        for (int i = 0; i < l; ++i){
            posb.pb(dup);
            rotate(dup.rbegin(), dup.rbegin()+1, dup.rend() );
            // cout << "--" << dup << endl;
        }
    }
    sort(posb.begin(), posb.end());
    cout << posb[0] << endl;
    return 0;
}