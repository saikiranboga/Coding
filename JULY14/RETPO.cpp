#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long int x, y;
		cin >> x >> y;
		long long int mod_x = abs(x);
		long long int mod_y = abs(y);
		long long int ans = 0;
		long long int diff;
		if(mod_x > mod_y){
			ans += mod_y*2;
			diff = mod_x - mod_y;
			ans += ((((diff+1)/2)*3)+(diff/2));
		} else{
			ans += mod_x*2;
			diff = mod_y - mod_x;
			ans += (((diff/2)*3)+((diff+1)/2));
		}
		cout << ans << endl;
	}
	return 0;
}