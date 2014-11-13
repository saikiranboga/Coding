#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAXN 10005
#define inf 1000000000

typedef struct Node {
    int lsum, rsum, sum, maxs;
}Node;

int lsum[4*MAXN];
int rsum[4*MAXN];
int sum[4*MAXN];
int maxs[4*MAXN];

int A[MAXN];
int cumsum[MAXN];
int N;

void update_val(int node_num) {
    int lt = node_num<<1;
    int rt = lt+1;
    sum[node_num]  = sum[lt] + sum[rt];
    lsum[node_num] = max( lsum[lt], sum[lt] + lsum[rt] );
    rsum[node_num] = max( rsum[rt], rsum[lt] + sum[rt] );

    maxs[node_num] = max( maxs[lt], maxs[rt] );
    maxs[node_num] = max( maxs[node_num], rsum[lt] + lsum[rt] );
    return;
}

void initialize(int node_num, int st, int ed) {
    if(st==ed){
        lsum[node_num] = A[st];
        rsum[node_num] = A[st];
        sum[node_num]  = A[st];
        maxs[node_num] = A[st];
        return;
    }
    int mid = (st+ed)>>1;
    initialize(node_num<<1, st, mid);
    initialize((node_num<<1)+1, mid + 1, ed);
    update_val(node_num);
    return;
}

Node query(int node_num, int st, int ed, int i, int j) {
    
    Node ret;
    
    if (st>ed || i>j) {
        ret.lsum = ret.rsum = ret.sum = ret.maxs = -inf;
        return ret;
    }
    
    if (st == i && ed == j) {
        ret.lsum = lsum[node_num];
        ret.rsum = rsum[node_num];
        ret.sum  = sum[node_num];
        ret.maxs = maxs[node_num];
        return ret;
    }

    int mid = (st+ed)>>1;
    int lt = node_num<<1;
    int rt = lt+1;
    if (j <= mid)
        return query(lt, st, mid, i, j);

    if (i > mid)
        return query(rt, mid+1, ed, i, j);

    Node left = query(lt, st, mid, i, mid);
    Node right = query(rt, mid + 1, ed, mid + 1, j);

    ret.lsum = max(left.lsum, left.sum + right.lsum);
    ret.rsum = max(right.rsum, left.rsum + right.sum);
    ret.sum = left.sum + right.sum;
    ret.maxs = max(left.maxs, right.maxs);
    ret.maxs = max(ret.maxs, left.rsum + right.lsum);
    return ret;
}

int getSum(int a, int b){
    if(a>b)
        return 0;
    return cumsum[b]-cumsum[a-1];
}

int solve(int x1, int y1, int x2, int y2){
    if(y1<x2){
        int l = query(1, 1, N, x1, y1).rsum;
        int midd = getSum( y1+1, x2-1 );
        int r = query(1, 1, N, x2, y2).lsum;
        return ( l + midd + r );
    }
    else{
        int l1 = query(1, 1, N, x1,   x2).rsum;
        int r1 = query(1, 1, N, x2+1, y2).lsum;

        int ret = max(l1, l1+r1);

        l1 = query(1, 1, N, x1,   y1).rsum;
        r1 = query(1, 1, N, y1+1, y2).lsum;

        ret = max(ret, max(l1, l1+r1));

        l1 = query(1, 1, N, x2, y1).maxs;

        ret = max(ret, l1);

        return ret;
    }
}

int main(){
    int t, ans, x, Q;
    int x1, x2, y1, y2;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        
        scanf("%d",&A[1]);
        cumsum[0] = 0;
        cumsum[1] = A[1];

        for(int i=2;i<=N;i++){
            scanf("%d",&A[i]);
            cumsum[i] = A[i] + cumsum[i-1];
        }

        initialize(1, 1, N);

        scanf("%d",&Q);

        while(Q--) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            printf("%d\n", solve(x1, y1, x2, y2) );
        }
    }
    return 0;
}