#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;

#define pb push_back
#define sz size()

#define LL long long int 

#define MAXN 300010
#define inf 10000000

LL A[MAXN], cum[MAXN];
LL tree[3*MAXN];
LL N;

void initialize(int node_num, int st, int ed) {
    if(st==ed){
        tree[node_num] = A[st];
        return;
    }
    int mid = (st+ed)>>1;
    if( (ed-st+1)%2 == 1)
        mid--;
    initialize(node_num<<1, st, mid);
    initialize((node_num<<1)+1, mid + 1, ed);
    tree[node_num] = (cum[ed]-cum[st-1]) + tree[node_num<<1] + tree[(node_num<<1)+1];
    // cout << st << " " << ed << " " << mid << endl;
    // cout << cum[ed]-cum[st-1] << " " << tree[node_num<<1] << " " << tree[(node_num<<1)+1] << endl;
    return;
}

bool comp(LL a, LL b){
    return a>b;
}

int main(){
    scanf("%d",&N);
    cum[0] = 0;
    for(int i=1;i<=N;i++)
        scanf("%d",&A[i]);
    sort(A+1, A+N+1);
    for(int i=1;i<=N;i++)
        cum[i] = cum[i-1] + A[i];

    LL rev_cum[N+1];
    rev_cum[N] = A[N];
    
    for(int i=N-1; i>0; i--)
        rev_cum[i] = rev_cum[i+1]+A[i];
    //initialize(1, 1, N);
    //cout << tree[1] << endl;
    LL ans = 0;
    for(int i=1; i<=N; i++){
        ans += rev_cum[i];
        if(i-1>0)
            ans += A[i-1];
    }
    cout << ans << endl;
    return 0;
}