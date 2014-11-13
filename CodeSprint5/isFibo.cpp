#include <iostream>
using namespace std;

#define MAX 1000
#define UP_LIMIT 10000000000LL
#define ll long long
ll fib[MAX];

int main(){

	fib[0] = 1;
	fib[1] = 1;
	ll i;
	for(i=2;i<MAX && fib[i-1] < UP_LIMIT;i++){
		fib[i] = fib[i-1] + fib[i-2];
		//cout << i << " " << fib[i] << endl;
	}
	ll j, n, t;
	cin >> t;
	while(t--){
		cin >> n;
		for(j=0;j<i;j++){
			if(fib[j] == n){
				cout << "IsFibo\n";
				break;
			}
		}
		if(j == i)
			cout << "IsNotFibo\n";
	}
	return 0;
}