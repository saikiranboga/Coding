#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int t = 20;
	srand(time(NULL));
	cout << t << endl;
	while(t--){
		int n = 1+rand()%1000;
		cout << n << endl;
		vector<int> v;
		for(int i=0;i<n;i++)
			v.push_back(i+1);
		random_shuffle(v.begin(), v.end());
		for(int i=0;i<n;i++)
			cout << v[i] << " ";
		cout << endl;
	}
	return 0;
}