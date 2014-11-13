/*
Segment Tree Lazy propogation implementation
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define max(a,b) ( (a)>(b)?(a):(b) )

struct Node {
    int max;
    int lazy;
};

struct SegTree {

    const static int MAXN = 10010;
    Node* tree[4 * MAXN];
    int A[MAXN];
    int N;

    SegTree(int NN){
        N = NN;
    }

    void initialize(int node_num, int st, int ed) {
        tree[node_num] = new Node();
        tree[node_num]->lazy = 0;
        if (st == ed) {
            tree[node_num]->max  = 0;
            return;
        }
        int mid = (st + ed) / 2;
        initialize(node_num * 2, st, mid);
        initialize(node_num * 2 + 1, mid + 1, ed);
        tree[node_num]->max = 0;
        return;
    }

    void refresh(int node_num, int st, int ed){
        if(tree[node_num]->lazy>0){
            tree[node_num]->max += tree[node_num]->lazy;
            if(st!=ed){
                tree[node_num*2]->lazy += tree[node_num]->lazy;
                tree[node_num*2+1]->lazy += tree[node_num]->lazy;
            }
            tree[node_num]->lazy = 0;
        }
        return;
    }

    void update(int node_num, int st, int ed, int i, int j) {

        // query seg doesn't lie in the current segment
        if (st>ed || i > ed || j < st){
            refresh(node_num, st, ed);
            return;
        }

        // current segment lies entirely in the query interval
        // change lazy flag and refresh node_num
        if(st>=i && ed<=j){
            tree[node_num]->lazy += 1;
            refresh(node_num, st, ed);
            return;
        }

        int mid = (st + ed) / 2;

        // cur segment overlaps query interval.
        
        // refresh the current node
        refresh(node_num, st, ed);

        // call updates on children
        update(node_num * 2, st, mid, i, j);
        update(node_num * 2 + 1, mid + 1, ed, i, j);

        // then update the node value, if not leaf
        if(st!=ed)
            tree[node_num]->max = max(tree[node_num*2]->max , tree[node_num*2+1]->max);
        
        return;
    }

    int query(int node_num, int st, int ed, int i, int j) {
        // query seg out of current seg
        if(st>ed || i>ed || j<st)
            return 0;

        // refresh the current seg
        refresh(node_num, st, ed);

        // query seg lies entirely in the cur seg, then return 
        // the sum (this seg is not lazy, as we have already refreshed it above)
        if(st>=i && ed<=j)
            return tree[node_num]->max;

        int mid = (st+ed) / 2;

        if(j<=mid)
            return query(node_num*2, st, mid, i, j);
        else if(i > mid)
            return query(node_num*2 + 1, mid+1, ed, i, j);

        // cur seg overlaps query seg
        return max( query(node_num*2, st, mid, i, mid) , query(node_num*2 + 1, mid+1, ed, mid+1, j) );
    }
};

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int N, type, x, y;
        scanf("%d",&N);
        int _N = 10010;
        SegTree* ST = new SegTree(_N);

        ST->initialize(1, 1, _N);

        while(N--){
            scanf("%d %d", &x, &y);
            ST->update(1, 1, _N, x+1, y+1);
        }
        int ans = ST->query(1, 1, _N, 1, _N);
        printf("%d\n",ans);
    }
}