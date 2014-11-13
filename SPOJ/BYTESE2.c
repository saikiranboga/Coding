/*
Segment Tree Lazy propogation implementation
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define max(a,b) ( (a)>(b)?(a):(b) )
#define MAXN 1000010

inline void fastRead(int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
}


typedef struct Node {
    int max;
    int lazy;
}Node;


Node* tree[4 * MAXN];
int A[MAXN];
int N;

int lts[MAXN], rts[MAXN];

void initialize(int node_num, int st, int ed) {
    tree[node_num] = (Node*)malloc(1*sizeof(Node));
    tree[node_num]->lazy = 0;
    if (st == ed) {
        A[st] = 0;
        tree[node_num]->max  = 0;
        return;
    }
    int mid = (st + ed) >> 1;
    initialize( node_num<<1, st, mid);
    initialize( (node_num<<1)|1, mid + 1, ed);
    tree[node_num]->max = 0;
    return;
}

void refresh(int node_num, int st, int ed){
    if(tree[node_num]->lazy>0){
        tree[node_num]->max += tree[node_num]->lazy;
        if(st!=ed){
            tree[node_num<<1]->lazy += tree[node_num]->lazy;
            tree[(node_num<<1)|1]->lazy += tree[node_num]->lazy;
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
    update( node_num<<1, st, mid, i, j);
    update( (node_num<<1)|1, mid + 1, ed, i, j);

    // then update the node value, if not leaf
    if(st!=ed)
        tree[node_num]->max = max(tree[node_num<<1]->max , tree[(node_num<<1)|1]->max);
    
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
        return query(node_num<<1, st, mid, i, j);
    else if(i > mid)
        return query( (node_num<<1) | 1, mid+1, ed, i, j);

    // cur seg overlaps query seg
    return max( query(node_num<<1, st, mid, i, mid) , query( (node_num<<1)|1, mid+1, ed, mid+1, j) );
}

int main(){
    int t;
    fastRead(&t);
    while(t--){
        int Q, x, y;
        fastRead(&Q);
        int i;
        N = 0;
        for(i=0;i<Q;i++){
            fastRead(&x);
            fastRead(&y);
            lts[i] = x+1;
            rts[i] = y+1;
            N = max(N, y+1);
        }
        N += 10;
        initialize(1, 1, N);

        for(i=0;i<Q;i++)
            update(1, 1, N, lts[i], rts[i]);
        int ans = query(1, 1, N-1, 1, N-1);
        printf("%d\n",ans);
    }
    return 0;
}