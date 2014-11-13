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
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int orders[m];
		int seen[401];
		memset( seen, 0, sizeof(seen) );
		
		int n_distinct = 0;
		int ind_first_n_distinct = 0;

		int sitting[401];
		memset( sitting, 0, sizeof(sitting) );

		rep(i,m){
			cin >> orders[i];
			if( !seen[ orders[i] ] ){
				n_distinct++;
				seen[ orders[i] ] = 1;
				
				if(n_distinct<=n)
					sitting[ orders[i] ] = 1;

				if( n_distinct == n )
					ind_first_n_distinct = i;
			}
		}

		if(n_distinct<=n){
			cout << n_distinct << endl;
			continue;
		}

		int ans = n;

		fu(i, ind_first_n_distinct+1, m-1){
			if(sitting[ orders[i] ]==1)
				continue;
			int mx = -1;
			int mx_ord;
			rep(j,401){
				if(sitting[j]){
					int k;
					for(k=i+1; k<m && orders[k]!=j; k++);
					if(k>mx){
						mx = k;
						mx_ord = j;
					}
				}
			}
			sitting[ mx_ord ] = 0;
			sitting[ orders[i] ] = 1;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}