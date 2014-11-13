#include <bits/stdc++.h>
using namespace std;

#define M 100010


typedef struct NODE
{
	// each node has left and right pointers(indices of the nodes are stored)
	int cnt, l, r;
	NODE(int cnt=0, int l=0, int r=0) :
		cnt(cnt), l(l), r(r) {};
}NODE;

int A[M], tmp[M], Root[M];
vector<int> adj[M];
NODE tree[20*M]; // NlogN space

map<int, int> MP, RMP;
int n, m;

int avail = 1;

int F[M], L[M];
int P[M][20];

// creates new node with cnt equals to that of the ref node
// and returns its index
int newNode(int ref)
{
	tree[avail].cnt = tree[ref].cnt; // using ref count
	tree[avail].l = tree[ref].l; // using ref left
	tree[avail].r = tree[ref].r; // using ref right
	avail++;
	return avail-1;
}

int insert(int idx, int val, int st, int ed){
	// the value of the node gives the position to insert

	// if val isn't in the range then return the current node
	// (no need to create new node)
	if(val>ed || val<st)
		return idx;

	idx = newNode(idx); // get new node with data same as idx node

	// leaf node
	if(st==val && ed==val){
		tree[idx].cnt++;
		return idx;
	}
	int mid = (st+ed)>>1;
	
	tree[idx].l = insert(tree[idx].l, val, st, mid); // either it remains same as that of previous segment tree's
													 // if val is not in range, else creates a new one if in range

	tree[idx].r = insert(tree[idx].r, val, mid+1, ed); // same as left

	tree[idx].cnt = tree[ tree[idx].l ].cnt + tree[ tree[idx].r ].cnt; // update the count

	// printf("New Node created for [%d,%d] with index %d\n",st,ed,idx);
	// printf("\t left = %d right = %d count = %d\n", tree[idx].l, tree[idx].r, tree[idx].cnt);

	return idx;
}

void dfs(int u, int f){

	Root[u] = insert( (f==-1?Root[0]:Root[f]), MP[A[u]], 1, n);
	F[u] = f;
	L[u] = ( f==-1 ? 0: L[f]+1);
	for(int i=0; i<adj[u].size(); i++)
		if(adj[u][i]!=f)
			dfs(adj[u][i], u);
	return;
}

void preprocess()
{
	dfs(1, -1);

	// initialize every element of P = -1
	memset(P, -1, sizeof(P));

	// first ancestor of every node is its parent
	for(int i=1; i<=n; i++)
		P[i][0] = F[i];

	// bottom-up DP
	for(int j=1; (1<<j)<=n; j++){
		for(int i=1; i<=n; i++){
			if(P[i][j-1] != -1)
				P[i][j] = P[P[i][j-1] ][j-1];
		}
	}
	return;
}

int lca(int p, int q){

	// making q nearer to the root, and q farther from the root
	if(L[p]<L[q])
		swap(p,q);

	int log;
	// log = floor[ L[p] ]
	for(log=1; (1<<log)<=L[p]; log++);
	log--;

	// find the ancestor of p which is on same level as that of q
	for(int i=log; i>=0; i--){
		if( (L[p]-(1<<i)) >= L[q] )
			p = P[p][i];
	}

	// now p is on same level as that of q

	// if q is the ancestor of p, then q is the common ancestor
	if(p==q)
		return p;

	// using meta-binary search
	for(int i=log; i>=0; i--){
		if( (P[p][i] != -1) && P[p][i]!=P[q][i] ){
			p = P[p][i];
			q = P[q][i];
		}
	}
	return F[p];
}

int query(int u, int v, int x, int xp, int k, int st, int ed){

	//if(k==1 && st==ed && ( tree[idx_r].cnt - tree[idx_l].cnt == k) )
	if(st==ed)
		return st;

	int mid = (st+ed)>>1;

	int on_left = tree[tree[u].l].cnt + tree[tree[v].l].cnt - tree[tree[x].l].cnt - tree[tree[xp].l].cnt;

	if(on_left>=k)
		return query(tree[u].l, tree[v].l, tree[x].l, tree[xp].l, k, st, mid);
	else
		return query(tree[u].r, tree[v].r, tree[x].r, tree[xp].r, k-on_left, mid+1, ed);
}

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

int main(){
	int x, y, k, idx;

	//scanf("%d %d",&n,&m);
	fastRead(&n);
	fastRead(&m);

	for(int i=1; i<=n; i++){
		//scanf("%d",&A[i]);
		fastRead(&A[i]);
		tmp[i] = A[i];
	}
	sort(tmp+1, tmp+n+1);

	for(int i=1;i<=n; i++){
		MP[ tmp[i] ] = i;
		RMP[ i ] = tmp[i];
	}

	for(int i=0; i<n-1; i++){
		//scanf("%d %d",&x,&y);
		fastRead(&x);
		fastRead(&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	preprocess();

	for(int i=1; i<=m; i++){
		//scanf("%d %d %d",&x, &y, &k);
		fastRead(&x);
		fastRead(&y);
		fastRead(&k);
		int LCAn = lca(x,y);
		idx = query(Root[x], Root[y], Root[LCAn], ( P[LCAn][0]==-1 ? Root[0] : Root[ P[LCAn][0] ] ), k, 1, n );
		printf("%d\n", RMP[idx]);
	}

	return 0;
}