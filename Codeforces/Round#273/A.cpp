#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

int main(){

	int x;
	int sum = 0;
	for(int i=0; i<5; i++){
		cin >> x;
		sum += x;
	}
	if(sum%5 == 0){
		if(sum/5 == 0)
			cout << -1 << endl;
		else
			cout << sum/5 << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}