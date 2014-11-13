#include <bits/stdc++.h>
using namespace std;

int main(){
	double c;
	while( (cin >> c) && c!=0.00){
		double n = 2.0;
		double tot = 1.0/2.0;
		int req = 1;
		n++;
		while(tot<c){
			tot += 1.0/n;
			req++;
			n++;
		}
		cout << req << " card(s)\n";
	}
	return 0;
}