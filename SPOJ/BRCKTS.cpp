#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int l, r;
};

class SegTree {
public:
    const static int MAXN = 50005;
    Node* tree[4 * MAXN];
    char A[MAXN];
    int N;

    SegTree(int NN){
        N = NN;
    }

    void initialize(int node_num, int st, int ed) {
        tree[node_num] = new Node();
        if (st == ed) {
            tree[node_num]->l = tree[node_num]->r = 0;
            if(A[st]=='(')
                tree[node_num]->l = 1;
            else
                tree[node_num]->r = 1;
            return;
        }
        int mid = (st + ed) / 2;
        initialize(node_num * 2, st, mid);
        initialize(node_num * 2 + 1, mid + 1, ed);
        update_val(node_num);
        return;
    }

    void update_val(int node_num) {
        int matches = min(tree[node_num*2]->l, tree[node_num*2+1]->r);
        tree[node_num]->l = (tree[node_num*2]->l - matches) + tree[node_num*2+1]->l;
        tree[node_num]->r = tree[node_num*2]->r + (tree[node_num*2+1]->r - matches);
        return;
    }

    bool update(int node_num, int st, int ed, int pos) {
        if (pos > ed || pos < st)
            return false;
        if (st == ed && st == pos) {
            if(A[st]=='(')
                A[st] = ')';
            else
                A[st] = '(';
            tree[node_num]->l = 1-tree[node_num]->l;
            tree[node_num]->r = 1-tree[node_num]->r;
            return true;
        }
        int mid = (st + ed) / 2;
        bool left_changed = false, right_changed = false;
        left_changed = update(node_num * 2, st, mid, pos);
        right_changed = update(node_num * 2 + 1, mid + 1, ed, pos);
        if (left_changed || right_changed) {
            update_val(node_num);
            return true;
        }
        return false;
    }
};

int main(){
    int tcases = 10;
    for(int tc=1; tc<=tcases; tc++){
        int N;
        scanf("%d",&N);
    
        SegTree* ST = new SegTree(N);
        char s[N+10];
        scanf("%s",&s);
        for(int i=0;i<N;i++)
            ST->A[i+1] = s[i];

        ST->initialize(1, 1, N);
        int Q,x;
        scanf("%d",&Q);

        cout << "Test " << tc << ":\n";

        while(Q--){
            scanf("%d",&x);
            if(x==0){
                if( (ST->tree[1]->l !=0) || (ST->tree[1]->r !=0) )
                    printf("NO\n");
                else
                    printf("YES\n");
            }
            else {
                ST->update(1, 1, N, x);
            }
        }
    }
}