#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n;
		vector<int> a;
		for(int i=0;i<n;i++){
			cin >> x;
			a.push_back(x);
		}
		sort(a.begin(), a.end());
		a.erase( unique(a.begin(), a.end()), a.end() );
		cout << a.size() << endl;
	}
	return 0;
}