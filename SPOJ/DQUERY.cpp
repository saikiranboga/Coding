#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define FF first
#define SS second

class SegTree {
public:
    const static int MAXN = 30005;
    int tree[4 * MAXN];
    int A[MAXN];
    int N;

    SegTree(int NN){
        N = NN;
    }

    void initialize(int node_num, int st, int ed) {
        if (st == ed) {
            tree[node_num] = 0;
            return;
        }
        int mid = (st + ed) / 2;
        initialize(node_num * 2, st, mid);
        initialize(node_num * 2 + 1, mid + 1, ed);
        return;
    }

    bool update(int node_num, int st, int ed, int pos, int val) {
        if (pos > ed || pos < st)
            return false;
        if (st == ed && st == pos) {
            A[st] = val;
            tree[node_num] = A[st];
            return true;
        }
        int mid = (st + ed) / 2;
        bool left_changed = false, right_changed = false;
        left_changed = update(node_num * 2, st, mid, pos, val);
        right_changed = update(node_num * 2 + 1, mid + 1, ed, pos, val);
        if (left_changed || right_changed) {
            tree[node_num] = tree[node_num<<1] + tree[(node_num<<1)|1];
            return true;
        }
        return false;
    }

    int query(int node_num, int st, int ed, int i, int j) {
        if (st == i && ed == j)
            return tree[node_num];
        int mid = (st + ed) / 2;

        if (j <= mid) {
            return query(node_num * 2, st, mid, i, j);
        }

        if (i > mid) {
            return query(node_num * 2 + 1, mid + 1, ed, i, j);
        }

        return query(node_num * 2, st, mid, i, mid) + query(node_num * 2 + 1, mid + 1, ed, mid + 1, j);
    }
};

bool compare(pair<int, pair<char, pair<int,int> > > a, pair<int, pair<char, pair<int,int> > > b){
    if(a.FF < b.FF)
        return true;
    else if(a.FF == b.FF){
        if( (a.SS).FF == 'N') return true;
        else return false;
    }
    return false;
}

int pos_last_occr[1000010];

int main(){
    ios::sync_with_stdio(false);
    int N, Q, x, y, pos, num, qnum;
    char type;
    scanf("%d",&N);
    
    SegTree* ST = new SegTree(N);
    vector< pair<int, pair<char, pair<int,int> > > > events;
    for(int i=1;i<=N;i++){
        scanf("%d",&x);
        events.push_back( mp( i,mp('N',mp(x,0)) ) );
    }

    scanf("%d",&Q);
    for(int i=1; i<=Q; i++){
        scanf("%d %d", &x, &y);
        events.push_back( mp( y,mp('Q',mp(x,i)) ) );
    }

    sort(events.begin(), events.end(), compare);

    ST->initialize(1, 1, N);
    memset(pos_last_occr, -1, sizeof(pos_last_occr));
    
    // for(int i=0; i<N+Q; i++){
    //     cout << "( " << events[i].FF << " ,( " << (events[i].SS).FF << ", " << (events[i].SS).SS.SS << ")\n";
    // }

    int ans[Q+1];

    for(int i=0; i<N+Q; i++){
        if( (events[i].SS).FF == 'N' ){
            pos = events[i].FF;
            num = ( (events[i].SS).SS ).FF;
            if(pos_last_occr[num] != -1){
                ST->update(1, 1, N, pos_last_occr[num], 0);
            }
            pos_last_occr[num] = pos;
            ST->update(1, 1, N, pos_last_occr[num], 1);
        }
        else{
            y = events[i].FF;
            x = ( (events[i].SS).SS ).FF;
            qnum = ( (events[i].SS).SS ).SS;
            ans[qnum] = ST->query(1, 1, N, x, y);
        }
    }

    for(int i=1; i<=Q; i++)
        printf("%d\n",ans[i]);
    return 0;
}