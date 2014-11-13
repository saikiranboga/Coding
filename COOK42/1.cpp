#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define ll long long 

int main(){
	ll t, i, j;
	cin >> t;

	while(t--){
		ll x1, x2, y1, y2;
		ll x11, x22, y11, y22;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x11 >> y11 >> x22 >> y22;

		ll a1 = (y2-y1)*(x2-x1);
		ll a2 = (y22-y11)*(x22-x11);
		
		ll left = max(x1, x11);
		ll right = min(x2, x22);
		ll bottom = max(y1, y11);
		ll top = min(y2, y22);

		ll a3 = 0;
		if( (top>bottom) && (right>left))
			a3 = (top-bottom)*(right-left);

		ll ans = a1+a2-a3;
		cout << ans << endl;
	}
	return 0;
}