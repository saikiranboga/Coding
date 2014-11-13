#include <iostream>
using namespace std;

int main(){
	int n,m;
	cin >> n;
	string s;
	int pts[n][2];
	int g[n][n];
	int check[n][n];
	int out[n*n][2];

	for(int i=0;i<n;i++){
		cin >> pts[i][0] >> pts[i][1];
	}

	m = 0;

	for(int i=0;i<n;i++){
		cin >> s;
		for(int j=0;j<n;j++){
			check[i][j] = 0;
			if(s[j] == 'N')
				g[i][j] = 0;
			else{
				g[i][j] = 1;
				m++;
			}
		}
	}

	m /= 2;
	int idx = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(g[i][j] && !check[i][j]){
				out[idx][0] = i;
				out[idx][1] = j;
				idx++;
				check[i][j] = 1;
				check[j][i] = 1;
			}
		}
	}

	cout << m << endl;
	for(int i=0;i<idx;i++){
		cout << 1 << " " << out[i][0] << " " << out[i][1] << endl;
	}

	return 0;
}