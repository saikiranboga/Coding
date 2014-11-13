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

int sumd(LL n){
	int ret = 0;
	while(n>0){
		ret += n%10;
		n = n/10;
	}
	return ret;
}

LL pwr(LL b, LL n){
	if(b==1)
		return 1;
	if(n==0)
		return 1;
	if(n==1)
		return b;
	LL ret = pwr(b, n/2);
	ret = ret*ret;
	if(n&1 != 0)
		ret = ret*b;
	return ret;
}

int main(){

	LL a,b,c;
	cin >> a >> b >> c;
	vector<LL> nums;
	for(LL i=1; i<=81; i++){
		LL res = ( b*pwr(i,a) ) + c;
		int sd = sumd(res);
//		cout << sd << " " << res << endl;
		if(res<inf && sd == i)
			nums.pb(res);
	}
	
	cout << nums.sz << endl;
	rep(i, nums.sz)
		cout << nums[i] << " ";
	if(nums.sz>0)
		cout << endl;
	return 0;
}