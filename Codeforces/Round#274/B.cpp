#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define LL long long int

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

bool comp(PII a, PII b){
	if(a.ff == b.ff)
		return (a.ss <= b.ss);
	return (a.ff <= b.ff);
}

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    PII h[n];

    int avg = 0;

    for(int i=0; i<n; i++){
    	cin >> a[i];
    	avg += a[i];
    	h[i].ff = a[i];
    	h[i].ss = i;
    }

    int posb = 1;
    if(avg%n == 0)
    	posb = 0;

    sort(h, h+n, comp);

    vector< PII > ops;

    int m = 0;
    for(int i=0; i<k; i++){
    	if( h[n-1].ff - h[0].ff <= posb)
    		break;
    	h[n-1].ff -= 1;
    	h[0].ff += 1;
    	m++;
    	ops.pb( mp(h[n-1].ss, h[0].ss) );
    	sort(h, h+n, comp);
    }

    int s = h[n-1].ff - h[0].ff;

    cout << s << " " << m << endl;
    for(int i=0; i<ops.sz; i++)
    	cout << ops[i].ff+1 << " " << ops[i].ss+1 << endl;
    cout << endl;

    return 0;
}