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

int ar[1000010];
int prev[1000010], nxt[1000010];
int rem;
void mark(int cur, int idx){
    if(rem==0)
        return;
    if(prev[cur] != -1 && prev[cur]!=0 && ar[idx-2]==-1){
        ar[idx-2] = prev[cur];
        rem--;
        mark(ar[idx-2], idx-2);
    }
    if(nxt[cur] != -1 && nxt[cur]!=0 && ar[idx+2]==-1){
        ar[idx+2] = nxt[cur];
        rem--;
        mark(ar[idx+2], idx+2);
    }
    return;
}

int main(){
    int n;
    cin >> n;
    int a, b;
    memset(ar, -1, sizeof(ar) );
    memset(prev, -1, sizeof(prev) );
    memset(nxt, -1, sizeof(nxt) );
    for (int i = 0; i < n; ++i){
        cin >> a >> b;
        prev[b] = a;
        nxt[a] = b;
    }
    ar[1] = nxt[0];
    ar[n-2] = prev[0];
    if(n-2 != 1){
        rem = n-2;
        mark(ar[1], 1);
        mark(ar[n-2],n-2);
    }
    else{
        rem = n-1;
        mark(ar[1], 1);
    }
    for (int i = 0; i < n; ++i)
        cout << ar[i] << " ";
    cout << endl;
    return 0;
}