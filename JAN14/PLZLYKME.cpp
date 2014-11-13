#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int p = 31, q = 32;
	long long int a[p+1][q+1];

	for (int i = 0; i <= p; ++i)
		for (int j = 0; j <= q; ++j)
			a[i][j] = 0;
	a[1][1] = 1;
	for(int i=2; i<=p; ++i){
		a[i][1] = 1;
		a[i][i] = 1;
	}

	for(int i=3; i<=p; ++i){
		for(int j=2; j<i; ++j){
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	}
	/*
	for (int i = 1; i<=p; ++i){
		for (int j = 1; j <= i; ++j){
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
	*/
	int T;
	cin >> T;

	while(T--){
		long long int L, D, S, C, _C, ans = 1;
		cin >> L >> D >> S >> C;		
		if(D >= 30)
			cout << "ALIVE AND KICKING\n";
		else{
			_C = C;
			for(int j=2;j<=D;j++){
				ans += _C*a[D][j];
				_C = _C*C;
			}
			ans *= S;
			if(ans >= L)
				cout << "ALIVE AND KICKING\n";
			else
				cout << "DEAD AND ROTTING\n";
		}
	}

	return 0;
}