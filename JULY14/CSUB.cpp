#include <iostream>
#include <string>
using namespace std;

int main(){

	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		string s;
		cin >> s;
		long ans = 0, count = 0;
		int sz = s.size();
		for(int i=sz-1; i>=0; i--){
			if(s[i]=='1')
				count++;
		}
		ans = (count*(count+1))/2;
		cout << ans << endl;
	}
	return 0;
}