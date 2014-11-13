#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

bool comp(PII a, PII b){
	if(a.ff == b.ff)
		return a.ss <= b.ss;
	return a.ff <= b.ff;
}

int fact(int x) {
  return (x == 1 ? x : x * fact(x - 1));
}

int main(){
	int n;
	cin >> n;
	PII h[n], temp[n];
	int x, y;
	for(int i=0; i<n; i++){
		cin >> x;
		h[i].ff = x;
		h[i].ss = i+1;
		temp[i].ff = x;
		temp[i].ss = i+1;
	}

	sort(h, h+n, comp);
	sort(temp, temp+n, comp);

	bool posb = false;

	int ans[3][n];

	int a = -1, b = -1;

	for(int i=0; i<n; i++){
		int elem = h[i].ff;
		int j = i+1;
		int ct = 1;
		while(j<n && h[j].ff==elem){
			j++;
			ct++;
		}
		if(ct >= 3){
			for(int kk=0;kk<3;kk++){
				for(int jj=0;jj<n;jj++)
					ans[kk][jj] = temp[jj].ss;
				next_permutation(temp+i, temp+j);
			}

			posb = true;
			break;
		}
	}

	if(posb==false){
		for(int i=0; i<n; i++){
			int elem = h[i].ff;
			int j = i+1;
			int ct = 1;
			while(j<n && h[j].ff==elem){
				j++;
				ct++;
			}
			if(ct==2 && a==-1){
				a = i;
				b = j;
			}
			if(perms>=3){

				for(int jj=0;jj<n;jj++)
					ans[0][jj] = temp[jj].ss;
				
				next_permutation(temp+a, temp+a+b);

				for(int jj=0;jj<n;jj++)
					ans[1][jj] = temp[jj].ss;

				next_permutation(temp+i, temp+j);

				for(int jj=0;jj<n;jj++)
					ans[2][jj] = temp[jj].ss;

				posb = true;
				break;
			}
		}
	}

	if(posb == true){
		cout << "YES\n";
		for(int kk=0;kk<3;kk++){
			for(int jj=0;jj<n;jj++)
				cout << ans[kk][jj] << " ";
			cout << endl;
		}
	}
	else{
		cout << "NO\n";
	}

	return 0;
}