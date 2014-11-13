#include <bits/stdc++.h>
using namespace std;

#define MX 1010

int F[MX], L[MX];
int P[MX][12];
int N, M, Q;

void preprocess()
{
	// initialize every element of P = -1
	memset(P, -1, sizeof(P));

	// first ancestor of every node is its parent
	for(int i=1; i<=N; i++)
		P[i][0] = F[i];

	// bottom-up DP
	for(int j=1; (1<<j)<=N; j++){
		for(int i=1; i<=N; i++){
			if(P[i][j-1] != -1)
				P[i][j] = P[P[i][j-1] ][j-1];
		}
	}
	return;
}

int query(int p, int q){

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

int main(int argc, char const *argv[])
{
	int t, x;
	cin >> t;
	for(int tc=1; tc<=t; tc++){
		cin >> N;
		F[1] = -1;
		L[1] = 0;
		for(int i=1;i<=N;i++){
			cin >> M;
			for(int j=0;j<M;j++){
				cin >> x;
				F[x] = i;
				L[x] = L[F[x]]+1;
			}
		}
		preprocess();
		cin >> Q;
		int p, q;
		cout << "Case " << tc << ":\n";
		for(int i=1; i<=Q; i++){
			cin >> p >> q;
			cout << query(p, q) << endl;
		}
	}
	return 0;
}