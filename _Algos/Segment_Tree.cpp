/*
Segment tree problem.(Not persistent Segment Tree)
complexity: O(N*logN + M*log10^9*logN)
O(N*logN) for storing sorted arrays at each node in seg tree (similar to merge sort)

if m is minimum element in array and M is maximum element then =>

for each query, we do binary search from m to M and check if we can find a element with 
k-1 nums less than it(we also need to check if the found element exists in the array).

*/
#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;

#define pb push_back
#define sz size()

#define MAXN 100005
#define inf 10000000

int A[MAXN];
vector<int> tree[3*MAXN];
int N, mn, mx, k;
bool found;

void update_val(int node_num) {
    int lt = node_num<<1;
    int rt = lt+1;
    int lsz = tree[lt].sz;
    int rsz = tree[rt].sz;
    int i=0, j=0;
    while(i!=lsz || j!=rsz){
        if(i==lsz){
            tree[node_num].pb( tree[rt][j] );
            j++;
        }
        else if(j==rsz){
            tree[node_num].pb( tree[lt][i] );
            i++;
        }
        else if(tree[lt][i]<=tree[rt][j]){
            tree[node_num].pb( tree[lt][i] );
            i++;
        }
        else{
            tree[node_num].pb( tree[rt][j] );
            j++;
        }
    }
    return;
}

void initialize(int node_num, int st, int ed) {
    if(st==ed){
        tree[node_num].pb(A[st]);
        return;
    }
    int mid = (st+ed)>>1;
    initialize(node_num<<1, st, mid);
    initialize((node_num<<1)+1, mid + 1, ed);
    update_val(node_num);
    /*
    cout << "{" << st << "," << ed << "} :- (";
    for(int i=0;i<tree[node_num].sz; i++)
        cout << tree[node_num][i] << " ";
    cout << endl;
    */
    return;
}

// this fn returns number of numbers which are less than num in range [i,j]
int query(int node_num, int st, int ed, int i, int j, int num) {
    vector<int>::iterator it;
    int id;
    if (st == i && ed == j) {
        it = upper_bound(tree[node_num].begin(), tree[node_num].end(), num-1);
        id = ( it-tree[node_num].begin() );
        if( ( id<tree[node_num].sz ) && ( tree[node_num][id]==num ) )
            found = true;
        //cout << "[" << st << "," << ed << "] : "<< id << " " << *it << endl;
        return id;
    }

    int mid = (st+ed)>>1;
    int lt = node_num<<1;
    int rt = lt+1;
    if (j <= mid)
        return query(lt, st, mid, i, j, num);

    if (i > mid)
        return query(rt, mid+1, ed, i, j, num);

    return query(lt, st, mid, i, mid, num) + query(rt, mid + 1, ed, mid + 1, j, num);
}

int solve(int x, int y){
    // we do bin search on possible value of the Kth num
    // there is only one number which has k-1 numbers
    // less than it in the range [x,y]
    int l = mn;
    int r = mx;
    int mid;
    int nums_less;
    while(l<=r){
        found = false;
        mid = (l+r)>>1;
        nums_less = query(1, 1, N, x, y, mid);
        //cout << mid << " : " << nums_less << " " << found << endl;
        if( (nums_less==k-1)  && found )
            return mid;
        else if( nums_less > k-1)
            r = mid-1;
        else
            l = mid+1;
    }
}

int main(){
    int t, ans, Q;
    int x, y;
    scanf("%d %d",&N,&Q);
    mn = inf;
    mx = -inf;
    for(int i=1;i<=N;i++){
        scanf("%d",&A[i]);
        if(A[i]>mx)
            mx = A[i];
        if(A[i]<mn)
            mn = A[i];
    }

    initialize(1, 1, N);
    while(Q--){
        scanf("%d %d %d",&x, &y, &k);
        printf("%d\n",solve(x, y));
    }
    return 0;
}