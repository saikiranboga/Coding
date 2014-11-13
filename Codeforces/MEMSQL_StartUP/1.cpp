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
	int n,m;
	cin >> n >> m;
	if(n==1 && m==1){
		cout << "1 1" << endl;
		cout << "0 0" << endl;
		cout << "1 0" << endl;
		cout << "0 1" << endl;
	}
	else if(n==0){
		cout << "0 1\n";
		cout << "0 " << m << endl;
		cout << "0 0\n";
		cout << "0 " << m-1 << endl;
	}
	else if(m==0){
		cout << "1 0\n";
		cout << n << " 0\n";
		cout << "0 0\n";
		cout << n-1 << " 0\n";
	}
	else if(m<2 || n<2){
		if(n>=m){
			cout << 0 << " " << 0 << endl;
			cout << n << " " << m << endl;
			cout << 0 << " " << m << endl;
			cout << n << " " << 0 << endl;
		}
		else{
			cout << 0 << " " << 0 << endl;
			cout << n << " " << m << endl;
			cout << n << " " << 0 << endl;
			cout << 0 << " " << m << endl;
		}
	}
	else if(n <= m){
		cout << "1 0" << endl;
		cout << n << " " << m <<endl;
		cout << "0 0" << endl;
		cout << n << " " << m-1 << endl;
	}
	else{
		cout << "0 1" << endl;
		cout << n << " " << m <<endl;
		cout << "0 0" << endl;
		cout << n-1 << " " << m << endl;
	}
	
	return 0;
}