/*
Persistent segment tree
complexity: O( (N+M)logN )
make segment tree for each node as we insert,
therefore totally we have N segment trees,
each with ceil(logN)+1 new nodes,
therefor with total of O(NlogN) space complexity.

for each query of the type : kth number in sorted sub-array [a,b]
we solve this by taking segment trees a-1 and b, then
for each level we go see how many nodes are there in the left
if its <=k then the node lies to the left, else to the right with k val decrease by 
number of nodes in the left.

Note: This works bcoz the array contains distinct values. we should modify this
	  if required for repeated values.
*/
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
NODE tree[20*M]; // NlogN space

map<int, int> MP, RMP;
int n, m;

int avail = 1;

// creates new node with cnt equals to that of the ref node
// and returns its index
int newNode(int ref){
	tree[avail].cnt = tree[ref].cnt; // using ref count
	tree[avail].l = tree[ref].l; // using ref left
	tree[avail].r = tree[ref].r; // using ref right
	avail++;
	return avail-1;
}

int insert(int idx, int val, int st, int ed){
	// the value of the node gives the position to insert
	// (this is why this algo works for array of distict elements,
	//    modification is required for array with repeted elements

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

int query(int idx_l, int idx_r, int k, int st, int ed){

	//if(k==1 && st==ed && ( tree[idx_r].cnt - tree[idx_l].cnt == k) )
	if(st==ed)
		return st;

	int mid = (st+ed)>>1;

	int on_left = tree[tree[idx_r].l].cnt - tree[tree[idx_l].l].cnt;
	// printf("right: %d left: %d rc: %d lc: %d\n", idx_r, idx_l, tree[tree[idx_r].l].cnt, tree[tree[idx_l].l].cnt);
	// printf("[%d,%d] : %d\n", st, ed, on_left);

	if(on_left>=k)
		return query(tree[idx_l].l, tree[idx_r].l, k, st, mid);
	else
		return query(tree[idx_l].r, tree[idx_r].r, k-on_left, mid+1, ed);
}

int main(){
	scanf("%d %d",&n,&m);

	for(int i=1; i<=n; i++){
		scanf("%d",&A[i]);
		tmp[i] = A[i];
	}
	sort(tmp+1, tmp+n+1);

	for(int i=1;i<=n; i++){
		MP[ tmp[i] ] = i;
		RMP[ i ] = tmp[i];
	}

	for(int i=1; i<=n; i++)
		Root[i] = insert(Root[i-1], MP[A[i]], 1, n);

	// printf("\nRoots\n");
	// for(int i=1; i<=n; i++)
	// 	printf("%d: %d\n", i, Root[i]);
	// printf("\n");

	// printf("\n\nTree Nodes\n");
	// for(int i=1; i<=28; i++)
	// 	printf("%d: [%d,%d] > %d\n", i, tree[i].l, tree[i].r, tree[i].cnt);
	// printf("\n");

	int x, y, k, idx;
	for(int i=1; i<=m; i++){
		//cin >> x >> y >> k;
		scanf("%d %d %d",&x, &y, &k);
		idx = query(Root[x-1], Root[y], k, 1, n);
		//cout << RMP[idx] << endl;
		printf("%d\n", RMP[idx]);
	}

	return 0;
}