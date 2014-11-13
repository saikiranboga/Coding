#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
	
	LL t;
	cin >> t;
	while(t--){
		LL k;
		cin >> k;
		LL block = (k-1)/4;
		LL in_block = k%4;
		
		if(block)
			cout << block;
		
		switch(in_block){
			case 0:
				cout << "942\n";
				break;
			case 1:
				cout << "192\n";
				break;
			case 2:
				cout << "442\n";
				break;
			case 3:
				cout << "692\n";
				break;
		}
	}

	/*
	LL cub;
	for(LL i=192;i<5000;i++){
		cub = pow(i,3);
		int count = 0;
		for(int j=0;j<3;j++){
			if(cub%10==8)
				count++;
			else
				break;
			cub /= 10;
		}
		if(count==3)
			cout << i << endl;
	}
	*/
	return 0;
}