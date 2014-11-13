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

int val(string l){
	int lv = 0;
	fd(i, l.sz-1, 0){
		if(l[i]=='i'){
			if( (i-1>=0) && (l[i-1]>='2') && (l[i-1]<='9') )
				lv += (int)(l[i-1]-'0');
			else
				lv += 1;
		}
		else if(l[i]=='x'){
			if( (i-1>=0) && (l[i-1]>='2') && (l[i-1]<='9') )
				lv = lv + ( (int)(l[i-1]-'0')*10 );
			else
				lv += 10;
		}
		else if(l[i]=='c'){
			if( (i-1>=0) && (l[i-1]>='2') && (l[i-1]<='9') )
				lv = lv + ( (int)(l[i-1]-'0')*100 );
			else
				lv += 100;
		}
		else if(l[i]=='m'){
			if( (i-1>=0) && (l[i-1]>='2') && (l[i-1]<='9') )
				lv = lv + ( (int)(l[i-1]-'0')*1000 );
			else
				lv += 1000;
		}
	}
	return lv;
}

void conv(int n){
	int ones,tens,huns,thos;
	ones = n%10;
	n /= 10;
	
	tens = n%10;
	n /= 10;
	
	huns = n%10;
	n /= 10;

	thos = n%10;
	n /= 10;

	if(thos){
		if(thos!=1)
			cout << thos;
		cout << "m";
	}

	if(huns){
		if(huns!=1)
			cout << huns;
		cout << "c";
	}

	if(tens){
		if(tens!=1)
			cout << tens;
		cout << "x";
	}

	if(ones){
		if(ones!=1)
			cout << ones;
		cout << "i";
	}
}

int main(){
	int n;
	cin >> n;
	while(n--){
		string l,r;
		cin >> l >> r;
		int lv, rv;
		lv = val(l);
		rv = val(r);
		int res = lv + rv;
		conv(res);
		cout << endl;
	}
	return 0;
}