#include<bits/stdc++.h>
using namespace std;

#define LL long long int

LL mx1, mx2, cur, tmp;

class Node {
public:
    LL max1, max2;
};

class SegTree {
public:
    const static int MAXN = 200005;
    Node* tree[4 * MAXN];
    LL A[MAXN];
    LL N;

    SegTree(LL NN){
        N = NN;
    }

    void initialize(int node_num, int st, int ed) {
        tree[node_num] = new Node();
        if (st == ed) {
            tree[node_num]->max1 = A[st];
            tree[node_num]->max2 = -1;
            return;
        }
        int mid = (st + ed) / 2;
        initialize(node_num * 2, st, mid);
        initialize(node_num * 2 + 1, mid + 1, ed);
        update_val(node_num);
        return;
    }

    void update_val(int node_num) {
        mx1 = tree[node_num*2]->max1;
        mx2 = tree[node_num*2]->max2;
        cur = tree[node_num*2 + 1]->max1;
        if(cur>mx1){
            mx2 = mx1;
            mx1 = cur;
        }
        else if(mx1>=cur && cur>mx2){
            mx2 = cur;
        }

        cur = tree[node_num*2 + 1]->max2;
        if(cur>mx1){
            mx2 = mx1;
            mx1 = cur;
        }
        else if(mx1>=cur && cur>mx2){
            mx2 = cur;
        }
        tree[node_num]->max1 = mx1;
        tree[node_num]->max2 = mx2;
        return;
    }

    bool update(int node_num, int st, int ed, int pos, LL val) {
        if (pos > ed || pos < st)
            return false;
        if (st == ed && st == pos) {
            A[st] = val;
            tree[node_num]->max1 = A[st];
            return true;
        }
        int mid = (st + ed) / 2;
        bool left_changed = false, right_changed = false;
        left_changed = update(node_num * 2, st, mid, pos, val);
        right_changed = update(node_num * 2 + 1, mid + 1, ed, pos, val);
        if (left_changed || right_changed) {
            update_val(node_num);
            return true;
        }
        return false;
    }

    Node* query(int node_num, int st, int ed, int i, int j) {
        if (st == i && ed == j)
            return tree[node_num];
        int mid = (st + ed) / 2;

        if (j <= mid) {
            return query(node_num * 2, st, mid, i, j);
        }

        if (i > mid) {
            return query(node_num * 2 + 1, mid + 1, ed, i, j);
        }

        Node* left = query(node_num * 2, st, mid, i, mid);
        Node* right = query(node_num * 2 + 1, mid + 1, ed, mid + 1, j);

        Node* ret = new Node();
        mx1 = left->max1;
        mx2 = left->max2;
        cur = right->max1;
        if(cur>mx1){
            mx2 = mx1;
            mx1 = cur;
        }
        else if(mx1>=cur && cur>mx2){
            mx2 = cur;
        }

        cur = right->max2;
        if(cur>mx1){
            mx2 = mx1;
            mx1 = cur;
        }
        else if(mx1>=cur && cur>mx2){
            mx2 = cur;
        }
        ret->max1 = mx1;
        ret->max2 = mx2;
        return ret;
    }
};

int main(){
    LL N,x;
    cin >> N;
    
    SegTree* ST = new SegTree(N);

    for(int i=1;i<=N;i++){
        cin >> x;
        ST->A[i] = x;
    }

    ST->initialize(1, 1, N);
    LL Q;
    cin >> Q;
    char type;
    LL y;

    while(Q--) {
        cin >> type >> x >> y;
        if(type=='U')
            ST->update(1, 1, N, x, y);
        else {
            Node* ans = ST->query(1, 1, N, x, y);
            LL out = ans->max1 + ans->max2;
            cout << out << endl;
        }
    }
}