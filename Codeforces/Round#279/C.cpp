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

#define MX 1000010

int lt[MX], rt[MX];
bool p[MX], q[MX];

int main(){
    string s;
    int n;
    cin >> s;
    n = s.sz;
    int a, b;
    cin >> a >> b;
    memset(lt,0,sizeof(lt));
    memset(rt,0,sizeof(rt));
    memset(p,false,sizeof(p));
    memset(q,false,sizeof(q));
    
    lt[0] = (s[0]-'0')%a;
    if(lt[0]==0)
        p[0] = true;
    for(int i = 1; i < n; ++i){
        lt[i] = ((lt[i-1]*10)%a + (s[i]-'0')%a)%a;
        if(lt[i]==0)
            p[i] = true;
    }

    rt[n-1] = (s[n-1]-'0')%b;
    if(rt[n-1]==0)
        q[n-1] = true;
    int pw = 10;
    for(int i=n-2; i>=0; i--){
        rt[i] =  (( ((s[i]-'0')%b) * (pw%b) )%b + rt[i+1]%b)%b;
        pw = ((pw%b)*(10%b))%b;
        if(rt[i]==0)
            q[i] = true;
    }
    int idx = -1;
    for(int i=0; i < n-1; ++i){
        if(p[i] && q[i+1] && (s[i+1]!='0')){
            idx = i;
            break;
        }
    }
    if(idx==-1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        for(int i = 0; i <= idx; ++i)
            cout << s[i];
        cout << endl;
        for(int i = idx+1; i < n; ++i)
            cout << s[i];
        cout << endl;
    }
    return 0;
}