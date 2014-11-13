#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long LL;
vector<vector<int> > lasts(10);
void precalc(){
for(int n=2;n<10;n++){
	int ld = n;
	do{
		lasts[n].pb(ld);
		ld = (ld*n)%10;
	}while(ld!=n);
}
}
int main(){
	precalc();
	int t;
	LL b;
	int lastDig;
	string a;
	cin >> t;
	while(t--){
		cin >> a >> b;
		lastDig = a[a.size()-1]-'0';
		if(lastDig == 0)
			cout << 0 << endl;
		else if(b==0 || lastDig==1){
			cout << 1 << endl;
		}
		else{
			int id = b % lasts[lastDig].size();
			if(id!=0)
				cout << lasts[lastDig][id-1] << endl;
			else
				cout << lasts[lastDig][lasts[lastDig].size()-1] << endl;
		}
	}
	return 0;
}