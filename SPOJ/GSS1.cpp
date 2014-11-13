#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

#define PI 3.1415926
#define inf 1000000000

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) cout << n

#define MAXN 50010

typedef struct node
{
	LL max, maxR, maxL, sum;
}NODE;

NODE tree[4*MAXN];
LL A[MAXN];
LL n;

void initialize(int nod, int b, int e){
	if(b==e)
		tree[nod].max = tree[nod].maxL = tree[nod].maxR = tree[nod].sum = A[b];
	else{
		initialize(2*nod, b, (b+e)/2);
		initialize(2*nod+1, (b+e)/2+1, e );
		tree[nod].sum = tree[2*nod].sum + tree[2*nod+1].sum;

		//[new max]
		LL newMx = max(tree[2*nod].max, tree[2*nod+1].max);
		newMx = max(newMx, tree[2*nod].maxR + tree[2*nod+1].maxL);
		tree[nod].max = newMx;

		//[new left max]
		tree[nod].maxL = max(tree[2*nod].maxL, tree[2*nod].sum+tree[2*nod+1].maxL);

		//[new right max]
		tree[nod].maxR = max(tree[2*nod+1].maxR, tree[2*nod+1].sum+tree[2*nod].maxR);
	}
}

NODE query(int nod, int b, int e, int i, int j){
	// if the current interval is included in the 
	// query interval, return the node
	if(i<=b && j>=e)
		return tree[nod];

	int mid = (b+e)/2;
	if(j<=mid)
		return query(2*nod, b, mid, i, j);
	if(i>mid)
		return query(2*nod+1, mid+1, e, i, j);

	// get the left and right maximum sums
	NODE p1 = query(2*nod, b, mid, i, j);
	NODE p2 = query(2*nod+1, mid+1, e, i, j);

	NODE result;
	result.sum = p1.sum+p2.sum;

	// maximum
	LL newMx = max(p1.max, p2.max);
	newMx = max(newMx, p1.maxR+p2.maxL);
	result.max = newMx;

	// right maximum sum
	result.maxR = max(p2.maxR, p2.sum+p1.maxR);

	// left maximum sum
	result.maxL = max(p1.maxL, p1.sum+p2.maxL);

	return result;
}

int main(){
	scanf("%lld",&n);
	rep(i,n)
		scanf("%lld",&A[i]);

	initialize(1, 0, n-1);

	int q, x, y;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&x, &y);
		NODE ans = query(1, 0, n-1, x-1, y-1);
		printf("%lld\n",ans.max);
	}
	return 0;
}