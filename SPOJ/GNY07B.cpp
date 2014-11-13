#include <bits/stdc++.h>
using namespace std;

map<string,int> U;

int main(){
	U["kg"] = 1;
	U["l"]  = 2;
	U["lb"] = 3;
	U["g"]  = 4;
	int t;
	cin >> t;
	for(int i=1;i<=t;i++){
		double n;
		string unit;
		cin >> n >> unit;
		cout << i << " ";
		cout << fixed;
		switch(U[unit]){
			case 1:
				cout <<setprecision(4) << (n*2.2046) << " lb\n";
				break;
			case 2:
				cout << setprecision(4) << (n*0.2642) << " g\n";
				break;
			case 3:
				cout << setprecision(4) << (n*0.4536) << " kg\n";
				break;
			case 4:
				cout << setprecision(4) << (n*3.7854) << " l\n";
				break;
		}
	}
	return 0;
}