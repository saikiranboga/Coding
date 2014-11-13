#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int min;
};

class SegTree {
public:
    const static int MAXN = 100005;
    Node* tree[4 * MAXN];
    int A[MAXN];
    int N;

    SegTree(int NN){
        N = NN;
    }

    void initialize(int node_num, int st, int ed) {
        tree[node_num] = new Node();
        if (st == ed) {
            tree[node_num]->min = A[st];
            return;
        }
        int mid = (st + ed) / 2;
        initialize(node_num * 2, st, mid);
        initialize(node_num * 2 + 1, mid + 1, ed);
        tree[node_num]->min = min( tree[node_num * 2]->min, tree[node_num * 2 + 1]->min);
        return;
    }

    int query(int node_num, int st, int ed, int i, int j) {
        
        if (st == i && ed == j)
            return tree[node_num]->min;

        int mid = (st + ed) / 2;

        if (j <= mid) {
            return query(node_num * 2, st, mid, i, j);
        }

        if (i > mid) {
            return query(node_num * 2 + 1, mid + 1, ed, i, j);
        }

        return min ( query(node_num * 2, st, mid, i, mid), query(node_num * 2 + 1, mid + 1, ed, mid + 1, j) );
    }
};

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1; tc<=t; tc++){
        int N,x,Q;
        scanf("%d %d",&N, &Q);
        
        SegTree* ST = new SegTree(N);

        for(int i=1;i<=N;i++){
            scanf("%d",&x);
            ST->A[i] = x;
        }

        ST->initialize(1, 1, N);
        int type, y;
        printf("Scenario #%d:\n\n",tc);
        while(Q--) {
            scanf("%d %d", &x, &y);
            int ans = ST->query(1, 1, N, x, y);
            printf("%d\n",ans);
        }
    }
}
