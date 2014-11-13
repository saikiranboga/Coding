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
	srand( time(NULL) );
	int t = 10;
	while(t--){
		int N = 1+rand()%10;
		if(N%2==1)
			N++;
		LL x,y;
		float xf;
		LL ls = 0, rs = 0;
		cout << N << endl;
		
		//	[TYPE-1]

		for(int i=0;i<N;i++){
			x = 1+rand()%inf;
			cout << x << " ";
			if(i<N/2)
				ls += x;
			else
				rs += x;
		}

/*
		// [TYPE-2]
		int LO = 1, HI = 8;
		for(int i=0;i<N;i++){
			xf = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
			y = (LL)pow(10,xf);
			cout << y << " ";
			if(i<N/2)
				ls += y;
			else
				rs += y;
		}
*/
		cout << endl;
		cout << ls << " " << rs << endl;
	}
	return 0;
}