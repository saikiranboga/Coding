#include <iostream>

using namespace std;

bool done(int a[], int n){
	for(int i=2;i<=n;i++)
		if(a[i]-a[i-1]!=1)
			return false;
	return true;
}

int main(){
	int t,tc;
	cin >> t;
	tc = t;
	while(t--){
		int n;
		cin >> n;
		int pos[n+1], actual[n+1], next[n+1];
		pos[0] = actual[0] = next[0] = 0;
		for(int i=1;i<=n;i++)
			actual[i] = i;
		cout << "Reading...\n";
		for(int i=1;i<=n;i++)
			cin >> pos[i];
		for(int i=1;i<=n;i++)
			next[pos[i]] = actual[i];
		int steps = 1;
		cout << "Test Case #" << tc-t << ": \n";
		while(!done(next, n)){
			//for(int i=1;i<=n;i++)
			//	cout << next[i] << " ";
			//cout << endl;
			for(int i=1;i<=n;i++)
				actual[i] = next[i];
			for(int i=1;i<=n;i++)
				next[pos[i]] = actual[i];
			steps++;
		}
		cout << steps << endl;
	}
	return 0;
}