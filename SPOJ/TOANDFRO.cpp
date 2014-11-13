#include <iostream>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n;
	while(n!=0){
		cin >> s;
		int rows = s.size()/n;
		char msg[rows][n];
		int row = 0;

		int i, id=0;
		for(i=0;i<rows;i++){
			if(i%2==0){
				for(int j=0;j<n;j++){
					msg[i][j] = s[id++];
				}
			} else{
				for(int j=n-1;j>=0;j--){
					msg[i][j] = s[id++];
				}
			}
		}

		for(int j=0;j<n;j++){
			for(i=0;i<rows;i++){
				cout << msg[i][j];
			}
		}
		cout << endl;
		cin >> n;
	}
	return 0;
}