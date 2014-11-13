#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;

#define pb push_back
#define sz size()

#define MAXN 100005
#define inf 10000000

int A[MAXN];
int tree[3*MAXN];
int N, k;

void initialize(int node_num, int st, int ed) {
    if(st==ed){
        tree[node_num] = A[st];
        return;
    }
    int mid = (st+ed)>>1;
    initialize(node_num<<1, st, mid);
    initialize((node_num<<1)+1, mid + 1, ed);
    tree[node_num] = tree[node_num<<1] & tree[(node_num<<1) + 1];
    return;
}

int query(int node_num, int st, int ed, int i, int j) {
    if (st == i && ed == j)
        return tree[node_num];

    int mid = (st+ed)>>1;
    int lt = node_num<<1;
    int rt = lt+1;
    if (j <= mid)
        return query(lt, st, mid, i, j);

    if (i > mid)
        return query(rt, mid+1, ed, i, j);

    int l = query(lt, st, mid, i, mid);
    int r = query(rt, mid + 1, ed, mid + 1, j);
    return l&r;
}

int main(){
    int t, n,K;
    cin >> t;
    while(t--){
        scanf("%d %d",&n,&K);
        int all = ~0;
        int ar[n+1];
        N = 3*n;
        for(int i=1; i<=n; i++){
            scanf("%d",&ar[i]);
            all &= ar[i];
            A[i] = A[i+n] = A[i+2*n] = ar[i];
        }

        if(2*K+1>=n){
            for(int i=1; i<=n; i++)
                cout << all << " ";
            cout << endl;
            continue;
        }

        initialize(1, 1, N);
        int ans;
        for(int i=1; i<=n; i++){
            ans = query(1, 1, N, n+i-K, n+i+K);
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}