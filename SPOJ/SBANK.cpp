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
	int t, n;
	map<string, int> acc;
	char sarr[100];
	scanf("%d\n",&t);

	rep(tc,t){
		scanf("%d\n",&n);
		acc.clear();
		rep(i,n)
		{
			gets(sarr);
			string s(sarr);
			if(!acc.count(s)){
				acc[s] = 0;
			}
			acc[s]++;
		}
		if(tc!=t-1)
			getchar();
		map<string,int>::iterator it;

		for(it=acc.begin(); it!=acc.end(); it++){
			printf("%s%d\n",(it->ff).c_str(), it->ss);
		}
		printf("\n");
	}

	return 0;
}