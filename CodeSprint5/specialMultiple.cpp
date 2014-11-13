#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define MAX 1000000
vector<ll> xs;

void precalc(){
	xs.push_back(9);
	ll size = xs.size();
	int cur = 0;
	ll push;
	while(size+1 < MAX){
		push = xs[cur]*10;
		xs.push_back(push);
		push = xs[cur]*10 + 9;
		xs.push_back(push);
		cur++;
		size = xs.size();
	}
	return;
}

int main(){
	ll t, n;
	cin >> t;
	while(t--){
		cin >> n;
		precalc();
		for(ll i=0;i<MAX;i++){
			if(xs[i]%n == 0){
				cout << xs[i] << endl;
				break;
			}
		}
	}
	return 0;
}