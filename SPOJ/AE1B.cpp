#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k,s;
	cin >> n >> k >> s;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	int tot = 0, count = 0;
	for(int i=n-1;i>=0;i--){
		tot += a[i];
		count++;
		if(tot>=k*s)
			break;
	}
	cout << count << endl;
	return 0;
}