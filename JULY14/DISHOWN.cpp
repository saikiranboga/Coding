#include <iostream>
#include <cstring>
using namespace std;

#define OWNER 0
#define SCORE 1

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		// first dimension: dish number
		// second dimension 0: owner
		// second dimension 1: score
		int chefs_scores[n+1][2];
		memset(chefs_scores,0,sizeof(chefs_scores));
		for(int i=1;i<=n;i++){
			chefs_scores[i][OWNER] = i;
			cin >> chefs_scores[i][SCORE];
		}
		int q, type, x, y;
		cin >> q;
		while(q--){
			cin >> type >> x;
			if(type == 0){
				cin >> y;
				if(chefs_scores[x][OWNER]==chefs_scores[y][OWNER]){
					cout << "Invalid query!\n";
				} else{
					if(chefs_scores[x][SCORE]>chefs_scores[y][SCORE]){
						for(int i=1;i<=n;i++){
							if(chefs_scores[i][OWNER]==y)
								chefs_scores[i][OWNER] = x;
						}
					} else if(chefs_scores[x][SCORE]<chefs_scores[y][SCORE]){
						for(int i=1;i<=n;i++){
							if(chefs_scores[i][OWNER]==x)
								chefs_scores[i][OWNER] = y;
						}
					}
				}
			} else{
				cout << chefs_scores[x][OWNER] << endl;
			}
		}
	}
	return 0;
}