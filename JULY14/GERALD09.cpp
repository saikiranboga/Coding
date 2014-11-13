#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

	string fill_1 = "AAAA";
	string fill_2 = "AAAT";
	string fill_3 = "ATAT";
	string fill_5 = "AATG";
	string fill_4 = "ATTG";
	string fill_all = "ATGC";
	int t;
	cin >> t;
	srand(time(NULL));
	while(t--){
		int n,m,k,mod;
		cin >> n >> m >> k;
		char mat[n][m];
		/*
		//fill
		if(k<n*m){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					mat[i][j] = fill_1[(i*m+j)%4];
				}
			}
		}
		else if(k>=n*m && k<2*n*m){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					mat[i][j] = fill_2[(i*m+j)%4];
				}
			}
		}
		else if(k>=2*n*m && k<3*n*m){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					mat[i][j] = fill_3[(i*m+j)%3];
				}
			}
		}
		else if(k>=3*n*m && k<4*n*m){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					mat[i][j] = fill_5[(i*m+j)%4];
				}
			}
		}
		else if(k>=4*n*m && k<6*n*m){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					mat[i][j] = fill_4[(i*m+j)%4];
				}
			}
		}
		else{
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					mat[i][j] = fill_all[(i*m+j)%4];
				}
			}
		}
		*/

		if(k<=n*m || (k<=n*n*m && k<=n*m*m) )
			mod = 1;
		else if(k<=2.455*n*n*m || k<=2.455*n*m*m)
			mod = 2;
		else if(k<=0.355*n*n*m*m)
			mod = 3;
		else
			mod = 4;

		//fill
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				mat[i][j] = fill_all[rand()%mod];
			}
		}

		//output
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout << mat[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}