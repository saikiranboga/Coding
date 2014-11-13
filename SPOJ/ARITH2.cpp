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

	map<string,int> ops;
	ops["*"] = 1;
	ops["/"] = 2;
	ops["+"] = 3;
	ops["-"] = 4;

	LL t;
	cin >> t;
	while(t--){
		LL nums1, nums2;
		string s;
		cin >> nums1;
		cin >> s;
		while( s != "=" ){
			cin >> nums2;
			switch(ops[s]){
				case 1:
					nums1 = nums1*nums2;
					break;
				case 2:
					nums1 = nums1/nums2;
					break;
				case 3:
					nums1 = nums1+nums2;
					break;
				case 4:
					nums1 = nums1-nums2;
					break;
			}
			cin >> s;
		}
		cout << nums1 << endl;
	}
	return 0;
}