#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n,i;
	cin >> t;
	while(t--){
		cin >> n;
		i = 1;
		while( i*(i+1)<2*n ) i++;
		int block = i;
		int prev_end = ((block-1)*block)/2;
		int num,den;// = n - prev_end;
		if(block%2==0){
			num = n - prev_end;
			den = block+1-num;
		}
		else{
			den = n - prev_end;
			num = block+1-den;
		}
		cout << "TERM " << n << " IS " << num << "/" << den << endl;
	}
	return 0;
}