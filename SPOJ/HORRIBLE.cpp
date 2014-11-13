/*
Segment Tree Lazy propogation implementation
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int 

class Node {
public:
    LL sum;
    LL lazy;
};

class SegTree {
public:
    const static int MAXN = 100005;
    Node* tree[4 * MAXN];
    LL A[MAXN];
    int N;

    SegTree(int NN){
        N = NN;
    }

    void initialize(int node_num, int st, int ed) {
        tree[node_num] = new Node();
        tree[node_num]->lazy = 0;
        if (st == ed) {
            tree[node_num]->sum  = A[st];
            return;
        }
        int mid = (st + ed) / 2;
        initialize(node_num * 2, st, mid);
        initialize(node_num * 2 + 1, mid + 1, ed);
        tree[node_num]->sum = tree[2*node_num]->sum + tree[2*node_num+1]->sum;
        return;
    }

    void refresh(int node_num, int st, int ed){
        if(tree[node_num]->lazy>0){
            
            tree[node_num]->sum += (ed-st+1)*tree[node_num]->lazy;
            if(st!=ed){
                tree[node_num*2]->lazy += tree[node_num]->lazy;
                tree[node_num*2+1]->lazy += tree[node_num]->lazy;
            }
            tree[node_num]->lazy = 0;
        }
        return;
    }

    void update(int node_num, int st, int ed, int i, int j, int val) {

        // query seg doesn't lie in the current segment
        if (st>ed || i > ed || j < st){
            refresh(node_num, st, ed);
            return;
        }

        // current segment lies entirely in the query interval
        // change lazy flag and refresh node_num
        if(st>=i && ed<=j){
            tree[node_num]->lazy += val;
            refresh(node_num, st, ed);
            return;
        }

        int mid = (st + ed) / 2;

        // cur segment overlaps query interval.

        // refresh the current node
        refresh(node_num, st, ed);

        // call updates on children
        update(node_num * 2, st, mid, i, j, val);
        update(node_num * 2 + 1, mid + 1, ed, i, j, val);

        // then update the node value, if not leaf
        if(st!=ed)
            tree[node_num]->sum = tree[node_num*2]->sum + tree[node_num*2+1]->sum;
        
        return;
    }

    LL query(int node_num, int st, int ed, int i, int j) {
        // query seg out of current seg
        if(st>ed || i>ed || j<st)
            return 0;

        // refresh the current seg
        refresh(node_num, st, ed);

        // query seg lies entirely in the cur seg, then return 
        // the sum (this seg is not lazy, as we have already refreshed it above)
        if(st>=i && ed<=j)
            return tree[node_num]->sum;

        int mid = (st + ed) / 2;

        // cur seg overlaps query seg
        return query(node_num*2, st, mid, i, j) + query(node_num*2 + 1, mid+1, ed, i, j);
    }
};

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int N, Q, type, x, y, val;
        scanf("%d %d",&N, &Q);
        SegTree* ST = new SegTree(N);

        for(int i=1;i<=N;i++)
            ST->A[i] = 0;

        ST->initialize(1, 1, N);

        while(Q--) {
            scanf("%d %d %d", &type, &x, &y);
            if(x>y)
                swap(x,y);
            if(type==0){
                scanf("%d",&val);
                ST->update(1, 1, N, x, y, val);
            }
            else {
                LL ans = ST->query(1, 1, N, x, y);
                printf("%lld\n",ans);
            }
        }
    }
}


