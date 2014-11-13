#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while( (cin>>n) && n){
		int nums[n+1];
		for(int i=1;i<=n;i++)
			cin >> nums[i];
		bool amb = true;
		for(int i=1;i<=n;i++){
			if(nums[nums[i]]!=i){
				amb = false;
				break;
			}
		}
		if(amb)
			cout << "ambiguous\n";
		else
			cout << "not ambiguous\n";
	}
	return 0;
}