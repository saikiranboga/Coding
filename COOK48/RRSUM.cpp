#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int LL;

int main()
{
	LL N,m,q;
	cin >> N >> m;
	while(m--){
		cin >> q;
		if( (q<N+2) || (q>3*N) )
			cout << "0\n";
		else{
			LL ind = q-(N+2);
			cout << N-abs(N-1-ind) << endl;
		}
	}
	return 0;
}