#include<bits/stdc++.h>
using namespace std;

#define M 100010

int start[M], end[M];

class Node {
public:
    int max;
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
            tree[node_num]->max = 1;
            return;
        }
        int mid = (st + ed) / 2;
        initialize(node_num * 2, st, mid);
        initialize(node_num * 2 + 1, mid + 1, ed);
        update_val(node_num, st, ed);
        return;
    }

    void update_val(int node_num, int st, int ed) {
        int mid = (st + ed) >> 1;
        tree[node_num]->max = max( tree[node_num*2]->max , tree[node_num*2 + 1]->max );

        if(A[mid]==A[mid+1]){
            int frq = min(end[mid], ed) - max(start[mid], st) + 1;
            tree[node_num]->max = max(tree[node_num]->max, frq);
        }
        return;
    }

    int query(int node_num, int st, int ed, int i, int j) {
        if (st == i && ed == j)
            return tree[node_num]->max;

        int mid = (st + ed) / 2;

        if (j <= mid) {
            return query(node_num * 2, st, mid, i, j);
        }

        if (i > mid) {
            return query(node_num * 2 + 1, mid + 1, ed, i, j);
        }

        int lf = query(node_num * 2, st, mid, i, mid);
        int rf = query(node_num * 2 + 1, mid + 1, ed, mid + 1, j);
        int ret = max(lf, rf);
        if(A[mid]==A[mid+1]){
            int frq = min(end[mid], j) - max(start[mid], i) + 1;
            ret = max(ret, frq);
        }
        return ret;
    }
};

int main(){
    int N, Q, x, y;
    while( (cin>>N) && N ){
        
        cin >> Q;

        SegTree* ST = new SegTree(N);

        for(int i=1;i<=N;i++){
            scanf("%d",&x);
            ST->A[i] = x;
        }

        map<int, int> s, e;
        for(int i=1; i<=N; i++){
            if(s.find(ST->A[i])!=s.end())
                start[i] = s[ST->A[i]];
            else{
                s[ST->A[i]] = i;
                start[i] = i;
            }
        }

        for(int i=N; i>=1; i--){
            if(e.find(ST->A[i])!=e.end())
                end[i] = e[ST->A[i]];
            else{
                e[ST->A[i]] = i;
                end[i] = i;
            }
        }

        ST->initialize(1, 1, N);

        while(Q--) {
            scanf("%d %d", &x, &y);
            int ans = ST->query(1, 1, N, x, y);
            printf("%d\n",ans);
        }
    }
}