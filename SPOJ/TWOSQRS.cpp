#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
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

vector<LL> primes;
bool is_pr[1000010];

void pre(){
	memset(is_pr,true,sizeof(is_pr));
	is_pr[0] = is_pr[1] = false;
	LL p;
	fu(i,2,1000010-1){
		if(is_pr[i]==true){
			p = i+i;
			primes.pb(i);
			while(p<1000010){
				is_pr[p] = false;
				p += i;
			}
		}
	}
}

int main(){
	LL t;
	cin >> t;
	pre();
	//cout << primes[primes.sz-1] << endl;
	while(t--){
		LL N,p,num;
		cin >> N;
		bool possible = true;

		int i;
		for(i=0;possible && i<primes.sz;i++){
			p = primes[i];
			if(N%p==0 && N){
				LL count = 0;
				while(N && N%p==0){
					count++;
					N /= p;
				}
				if(p%4==3){
					if(count%2!=0){
						possible = false;
						break;
					}
				}
			}
		}
		if(possible && i==primes.sz && N){
			if(N%4==3)
				possible = false;
		}

		if(possible){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}