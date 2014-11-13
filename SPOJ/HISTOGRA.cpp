#include<bits/stdc++.h>
using namespace std;

#define LL long long int

class Node {
public:
    int minIdx;
};

class SegTree {
public:
    const static int MAXN = 100005;
    Node* tree[4 * MAXN];
    LL A[MAXN];
    LL N;

    SegTree(int NN){
        N = NN;
    }

    void initialize(int node_num, int st, int ed) {
        tree[node_num] = new Node();
        if (st == ed) {
            tree[node_num]->minIdx = st;
            return;
        }
        int mid = (st + ed) / 2;
        initialize(node_num * 2, st, mid);
        initialize(node_num * 2 + 1, mid + 1, ed);
        tree[node_num]->minIdx = (A[tree[node_num*2]->minIdx] < A[tree[node_num*2+1]->minIdx]) ? (tree[node_num*2]->minIdx) : (tree[node_num*2+1]->minIdx);
        return;
    }

    int query(int node_num, int st, int ed, int i, int j) {
        if (st == i && ed == j)
            return tree[node_num]->minIdx;

        int mid = (st + ed) / 2;

        if (j <= mid) {
            return query(node_num * 2, st, mid, i, j);
        }

        if (i > mid) {
            return query(node_num * 2 + 1, mid + 1, ed, i, j);
        }

        int lidx = query(node_num * 2, st, mid, i, mid);
        int ridx = query(node_num * 2 + 1, mid + 1, ed, mid + 1, j);
        return ( A[lidx]<A[ridx] ? lidx : ridx );
    }
};

LL getArea(SegTree* ST, int l, int r){
    
    if(l>r)
        return 0;

    int min_pos = ST->query(1, 1, ST->N, l, r);

    LL lA = getArea(ST, l, min_pos-1);
    LL rA = getArea(ST, min_pos+1, r);
    LL cA = (ST->A[min_pos])*(r-l+1);
    return max(cA,max(lA,rA));
}

int main(){
    int N,x;
    
    while( (cin >> N) && N){
        
        SegTree* ST = new SegTree(N);

        for(int i=1;i<=N;i++){
            scanf("%d",&x);
            ST->A[i] = x;
        }

        ST->initialize(1, 1, N);
        cout << getArea(ST, 1, N) << endl;
    }
}