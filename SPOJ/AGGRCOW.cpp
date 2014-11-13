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

int pos[100010];
int n,c;

bool okay(LL x){
	int lastpos = 0;
	int nCows = 1;
	fu(i,1,n-1){
		if(pos[i]-pos[lastpos]>=x){
			nCows++;
			if(nCows==c)
				return true;
			lastpos = i;
		}
	}
	return false;
}

int binSearch(){
	LL left = 0, right = inf;
	LL mid = (left+right)/2;
	while(left<right){
		mid = (left+right)/2;
		if(okay(mid)){
			left = mid+1;
		}
		else{
			right = mid;
		}
	}
	return left-1;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> c;
		rep(i,n)
			cin >> pos[i];
		sort(pos,pos+n);
		LL ans = binSearch();
		if(ans==-1)
			ans = 0;
		cout << ans << endl;
	}
	return 0;
}