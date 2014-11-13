#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while( (cin >> n) && n!=-1){
		int tot = 0;
		int ar[n];
		for(int i=0;i<n;i++){
			cin >> ar[i];
			tot += ar[i];
		}
		bool possible = true;
		if(tot%n!=0){
			possible = false;
		}
		if(possible){
			int ans = 0;
			int avg = tot/n;
			for(int i=0;i<n;i++){
				if(ar[i]>avg)
					ans += (ar[i]-avg);
			}
			cout << ans << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
	return 0;
}