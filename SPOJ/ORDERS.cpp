#include<bits/stdc++.h>
using namespace std;

#define M 200010

int moves[M], id[M];

class Node {
public:
    int sum;
};

class SegTree {
public:
    const static int MAXN = 200005;
    Node* tree[4 * MAXN];
    int A[MAXN];
    int N;

    SegTree(int NN){
        N = NN;
    }

    void initialize(int node_num, int st, int ed) {
        tree[node_num] = new Node();
        if (st == ed) {
            tree[node_num]->sum  = A[st];
            return;
        }
        int mid = (st + ed) / 2;
        initialize(node_num * 2, st, mid);
        initialize(node_num * 2 + 1, mid + 1, ed);
        tree[node_num]->sum = tree[node_num * 2]->sum + tree[node_num * 2 + 1]->sum;
        return;
    }

    bool update(int node_num, int st, int ed, int pos) {
        if (pos > ed || pos < st)
            return false;
        if (st == ed && st == pos) {
            A[st] = 0;
            tree[node_num]->sum  = A[st];
            return true;
        }
        int mid = (st + ed) / 2;
        bool left_changed = false, right_changed = false;
        
        left_changed = update(node_num * 2, st, mid, pos);
        right_changed = update(node_num * 2 + 1, mid + 1, ed, pos);

        if (left_changed || right_changed) {
            tree[node_num]->sum = tree[node_num * 2]->sum + tree[node_num * 2 + 1]->sum;
            return true;
        }
        return false;
    }

    int query(int node_num, int st, int ed, int pos) {
        if (st == ed)
            return st;
        int mid = (st + ed) / 2;

        if ( pos <= tree[node_num*2]->sum) {
            return query(node_num * 2, st, mid, pos);
        }
        else{
            return query(node_num * 2 + 1, mid + 1, ed, pos-tree[node_num*2]->sum);
        }
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int N,x;
        scanf("%d",&N);
        
        SegTree* ST = new SegTree(N);

        for(int i=1;i<=N;i++){
            cin >> moves[i];
            ST->A[i] = 1;
        }

        ST->initialize(1, 1, N);
        int pos;
        for(int i=N; i>=1; i--){
            pos = ST->query(1, 1, N, i-moves[i]);
            ST->update(1, 1, N, pos);
            id[i] = pos;
        }
        for(int i=1; i<=N; i++)
            cout << id[i] << " ";
        cout << endl;
    }
}