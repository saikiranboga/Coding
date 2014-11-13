#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	string s;
	for(int i=1;i<=t;i++){
		cin >> n >> s;
		s.erase(n-1,1);
		cout << i << " " << s << endl;
	}
	return 0;
}