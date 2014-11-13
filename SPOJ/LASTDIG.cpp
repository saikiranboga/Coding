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
	LL a,b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		if(a%10==0)
			cout << 0 << endl;
		else if(b==0 || a%10==1){
			cout << 1 << endl;
		}
		else{
			int id = b % lasts[a%10].size();
			if(id!=0)
				cout << lasts[a%10][id-1] << endl;
			else
				cout << lasts[a%10][lasts[a%10].size()-1] << endl;
		}
	}
	return 0;
}