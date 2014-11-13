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
	int n;
	cin >> n;
	int a[n],b[n],c[n],d[n];
	
	rep(i,n)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	vector<int> nums1, nums2;
	rep(i,n){
		rep(j,n){
			nums1.pb( a[i] + b[j] );
			nums2.pb( c[i] + d[j] );
		}
	}

	sort( nums2.begin(), nums2.end() );

	int siz = nums1.sz;
	int x;
	vector<int>::iterator low,high;
	LL ans = 0;
	rep(i,siz){
		x = -1*nums1[i];
		low = lower_bound(nums2.begin(), nums2.end(),x);
		high = upper_bound(nums2.begin(), nums2.end(),x);
		ans += (high-low);
	}
	cout << ans << endl;
	return 0;
}