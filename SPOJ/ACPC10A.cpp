#include <bits/stdc++.h>
using namespace std;

int main(){
	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	while( !(a1==0 && a2==0 && a3==0) ){
		if(a2-a1 == a3-a2)
			cout << "AP " << 2*a3-a2 << endl;
		else
			cout << "GP " << a3*(a3/a2) << endl;
		cin >> a1 >> a2 >> a3;
	}
	return 0;
}