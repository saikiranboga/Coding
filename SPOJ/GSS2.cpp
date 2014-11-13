#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define inf 100000000000LL
#define LL long long 

LL lsum[4*MAXN];
LL rsum[4*MAXN];
LL sum[4*MAXN];
LL maxs[4*MAXN];

LL A[MAXN];
LL N;

typedef struct Node {
    LL lsum, rsum, sum, maxs;
}Node;

void update_val(LL node_num) {
    LL lt = node_num<<1;
    LL rt = lt+1;
    sum[node_num]  = sum[lt] + sum[rt];
    lsum[node_num] = max( lsum[lt], sum[lt] + lsum[rt] );
    rsum[node_num] = max( rsum[rt], rsum[lt] + sum[rt] );

    maxs[node_num] = max( maxs[lt], maxs[rt] );
    maxs[node_num] = max( maxs[node_num], rsum[lt] + lsum[rt] );
    return;
}

void initialize(LL node_num, LL st, LL ed) {
    if(st==ed){
        lsum[node_num] = A[st];
        rsum[node_num] = A[st];
        sum[node_num]  = A[st];
        maxs[node_num] = A[st];
        return;
    }
    LL mid = (st+ed)>>1;
    initialize(node_num<<1, st, mid);
    initialize((node_num<<1)+1, mid + 1, ed);
    update_val(node_num);
    return;
}

bool update(LL node_num, LL st, LL ed, LL pos, LL val) {
    if (pos > ed || pos < st)
        return false;
    if (st == ed && st == pos) {
        A[st] = val;
        lsum[node_num] = val;
        rsum[node_num] = val;
        sum[node_num]  = val;
        maxs[node_num] = val;
        return true;
    }
    LL mid = (st + ed) / 2;

    bool left_changed = false, right_changed = false;
    left_changed = update( node_num<<1, st, mid, pos, val);
    right_changed = update( (node_num<<1) + 1, mid + 1, ed, pos, val);

    if (left_changed || right_changed) {
        update_val(node_num);
        return true;
    }
    return false;
}

Node query(LL node_num, LL st, LL ed, LL i, LL j) {
    
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

    LL mid = (st+ed)>>1;
    LL lt = node_num<<1;
    LL rt = lt+1;
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

typedef struct QRY{
    LL x, y, no;
}QRY;

bool comp(QRY a, QRY b){
    if(a.x==b.x)
        return a.y < b.y;
    return a.x <= b.x;
}

int main(){
    LL x, y, Q;
    scanf("%lld",&N);

    for(int i=1;i<=N;i++){
        scanf("%lld",&A[i]);
    }

    LL next[N+1];
    LL mp[200001];
    memset(mp, 0, sizeof(mp));
    mp[ A[N]+100000 ] = N;
    next[N] = 0;

    for(LL i=N-1; i>=1; i--){
        if( mp[ A[i]+100000 ] != 0 )
            next[ i ] = mp[ A[i]+100000 ];
        else
            next[ i ] = 0;
        mp[ A[i]+100000 ] = i;
    }

    LL marked[N+1];
    memset(marked, 0, sizeof(marked) );
    LL j;
    for(LL i=1; i<=N; i++){
        if(marked[i]>0)
            continue;
        marked[i] = 1;
        j = i;
        while(next[j]>0){
            A[ next[j] ] = 0;
            marked[ next[j] ] = 1;
            j = next[j];
        }
    }

    initialize(1, 1, N);

    scanf("%lld",&Q);
    Node ans;

    QRY qr[Q];
    LL op[Q];
    for(LL q=0; q<Q; q++){
        scanf("%lld %lld", &x, &y);
        qr[q].x = x;
        qr[q].y = y;
        qr[q].no = q;
    }
    sort(qr, qr+Q, comp);

    j = 0;
    for(LL i=1; i<=N; i++){
        while(qr[j].x == i){
            ans = query(1, 1, N, qr[j].x, qr[j].y);
            op[ qr[j].no ] = ans.maxs;
            j++;
        }
        if(next[i]>0)
            update(1, 1, N, next[i], A[i]);
    }

    for(LL i=0; i<Q; i++)
        printf("%lld\n", op[i]);
    return 0;
}