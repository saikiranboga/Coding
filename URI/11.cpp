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

int main(){
	int n, k, x;
	while( (cin >> k >> n) ){
		vector<int> seq;
		rep(i,k){
			cin >> x;
			seq.pb(x);
		}
		int seen[n+1];
		int prev[n+1];

		while(seq.sz != n){
			memset(seen, 0, sizeof(seen));
			int i;
			for(i=0; i<seq.sz; i++){
				if(!seen[seq[i]]){
					seen[seq[i]] = 1;
					prev[seq[i]] = i;
				}
				else{
					break;
				}
			}
			if(i==seq.sz)
				break;
			int st = prev[seq[i]];
			int ed = i;
			bool done = false;
			//duplicated
			if( seq.sz-ed >= ed-st ){
				for(i=0; i<ed-st; i++){
					if(seq[st+i]!=seq[ed+i])
						break;
				}
				if(i==ed-st){
					seq.erase(seq.begin()+ed,seq.begin()+ed+ed-st);
					done = true;
				}
			}
			if(!done){
				int mid = (ed-st)/2 + st;
				seq.erase(seq.begin()+mid+1, seq.begin()+ed+1);
			}
		}
		rep(i, seq.sz)
			cout << seq[i] << " ";
		cout << endl;
	}
	return 0;
}