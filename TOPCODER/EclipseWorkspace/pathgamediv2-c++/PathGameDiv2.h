#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class PathGameDiv2 {
	int n;
	public: int calc(vector<string> board) {
		n = board[0].size();
		int black_cnt = 0;
		int tot = 2*n;
		int dist[tot][tot];
		int inf = 1000000;

		for(int i=0; i<tot; i++)
			for(int j=0; j<tot; j++)
				dist[i][j] = inf;

		for(int i=0; i<tot; i++)
			dist[i][i] = 0;

		for(int i=0; i<2; i++){
			for(int j=0; j<n-1; j++){
				if(board[i][j]=='.'){
					if(board[i][j+1]=='.')
						dist[i*n+j][i*n+j+1] = 1;
					if(board[1-i][j]=='.')
						dist[i*n+j][(1-i)*n+j] = 1;
				}
				else{
					black_cnt++;
				}
			}
		}
		if(board[0][n-1]=='#')
			black_cnt++;
		if(board[1][n-1]=='#')
			black_cnt++;

		for(int k=0; k<tot; k++){
			for(int i=0; i<tot; i++){
				for(int j=0; j<tot; j++){
					if(dist[i][j]>dist[i][k]+dist[k][j])
						dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}

		int minm = min( dist[0][n-1], dist[0][tot-1] );
		minm = min( minm, dist[n][n-1] );
		minm = min( minm, dist[n][tot-1] );
		int ans = tot - minm - 1 - black_cnt;
		return ans;
	}

};
