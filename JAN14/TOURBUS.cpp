#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <assert.h>
using namespace std;

int n, m;
int pts[60][2];
int edges[60][60];
int trip[60][60];
int connected[60];
int check_edges[60][60];

void dfs(int node, int flag){
	if(flag == 0){
		for(int i=0; i<n; i++){
			if(edges[node][i]){
				if(connected[i] == 0){
					if(node < i)
						trip[node][i] = 1;
					else
						trip[i][node] = 1;
					//trip[i][node] = 1;
					connected[i] = 1;
					connected[node] = 1;
					return;
				}
				else if(connected[i] == 1){
					if(node < i)
						trip[node][i] = 1;
					else
						trip[i][node] = 1;
					//trip[i][node] = 1;
					connected[i] = 2;
					connected[node] = 2;
					for(int j=0;j<n;j++){
						if(trip[i][j]==1 && j!=node){
							connected[j] = 2;
							//trip[j][node] = 1;
							//trip[node][j] = 1;
							return;
						}
					}
					return;
				}
			}
		}
	}
	else if(flag == 1){
		for(int i=0; i<n; i++){
			if(edges[node][i]){
				if(connected[i] == 0){
					if(node < i)
						trip[node][i] = 1;
					else
						trip[i][node] = 1;
					//trip[i][node] = 1;
					connected[i] = 2;
					connected[node] = 2;
					for(int j=0;j<node;j++){
						if(trip[j][node]==1 && j!=i){
							//trip[j][i] = 1;
							//trip[i][j] = 1;
							connected[j] = 2;
							return;
						}
					}
					return;
				}
			}
		}
	}
	return;
}

void numTrips(){
	int out[1000];
	int len[1000];
	map<int, vector<int> > adj;
	int visited[n];
	int num_trips = 0;
	for(int i=0;i<n;i++)
		visited[i] = 0;

	for(int i=0;i<n;i++){
		int flag = 0;

		for(int j=0; j<i; j++){
			if(trip[j][i]==1){
				adj[i].push_back(j);
				flag = 1;
			}
		}

		for(int j=0; j<n; j++){
			if(trip[i][j]==1){
				if(j > i){
					adj[i].push_back(j);
					flag = 1;
				}
			}
		}
		if(flag==0)
			adj[i].push_back(-1);
	}
	int idx = 0, len_idx = 0;
	int size;

	for( map<int, vector<int> >::iterator iter = adj.begin(); iter != adj.end(); ++iter ) {
		if( (!visited[(*iter).first]) && ( (*iter).second[0] != -1)){
			out[idx++] = -1;
			num_trips++;
			out[idx++] = (*iter).first;
		}
		visited[(*iter).first] = 1;
		if(  (*iter).second[0] != -1){
			size =  (*iter).second.size();
			for(int ii=0;ii<size;ii++){
				if( !visited[ (*iter).second[ii] ]){
					
					visited[ (*iter).second[ii] ] = 1;
					out[idx++] = (*iter).second[ii];
					//if(out[idx-3] == -1){
						//check_edges[(*iter).first][(*iter).second[ii]] = 0;
						//check_edges[(*iter).second[ii]][(*iter).first] = 0;
					//}

					int lop = (*iter).second[ii];
					for(int jj=0; jj<adj[lop].size(); jj++){
						if(!visited[adj[lop][jj]]){
							out[idx++] = adj[lop][jj];
							visited[adj[lop][jj]] = 1;
							//check_edges[lop][adj[lop][jj]] = 0;
							//check_edges[adj[lop][jj]][lop] = 0;
						}
					}
				}
			}
		}
	}

	//assert(num_trips >= 1);
	//assert(num_trips <= ((n+m)/2));

	len[len_idx] = 0;
	for(int i=1;i<idx;i++){
		//cout << out[i] << " ";
		if(out[i] != -1)
			len[len_idx]++;
		else{
			//cout << "len: " << len[len_idx] << endl;
			len[++len_idx] = 0;
		}
	}

	int out_i = 1;
	for(int i=0; i<=len_idx; i++){
		if(len[i]>2){
			int x1 = out[out_i];
			int x2 = out[out_i+1];
			int x3 = out[out_i+2];
			//cout << "[x1][x2]:" << check_edges[x1][x2] << "[x2][x3]:" << check_edges[x2][x3] << "[x1][x3]:" << check_edges[x1][x3] << endl;
			if(edges[x1][x2] && edges[x2][x3]){
			//	cout << "changing: " << x1 << " " << x2 << " " << x3 << endl;
				check_edges[x1][x2] = 0;
				check_edges[x2][x1] = 0;

				check_edges[x2][x3] = 0;
				check_edges[x3][x2] = 0;
			}
			else if(edges[x1][x3] && edges[x3][x2]){

				//cout << "changing: " << x1 << " " << x2 << " " << x3 << endl;

				check_edges[x1][x3] = 0;
				check_edges[x3][x1] = 0;

				check_edges[x3][x2] = 0;
				check_edges[x2][x3] = 0;

				out[out_i] = x1;
				out[out_i+1] = x3;
				out[out_i+2] = x2;
			}
			else if(edges[x2][x1] && edges[x1][x3]){

				//cout << "changing: " << x1 << " " << x2 << " " << x3 << endl;

				check_edges[x2][x1] = 0;
				check_edges[x1][x2] = 0;

				check_edges[x1][x3] = 0;
				check_edges[x3][x1] = 0;

				out[out_i] = x2;
				out[out_i+1] = x1;
				out[out_i+2] = x3;

			}
		}
		else if(len[i] == 2){
			int x1 = out[out_i];
			int x2 = out[out_i+1];
			check_edges[x1][x2] = 0;
			check_edges[x2][x1] = 0;
		}
		out_i = out_i + len[i] + 1;
	}
/*

	for(int ii=0; ii<n; ii++){
		for(int jj=0; jj<n; jj++){
			cout << check_edges[ii][jj] << " ";
		}
		cout << endl;
	}
*/

	for(int ii=0; ii<n; ii++){
		for(int jj=0; jj<n; jj++){
			if(check_edges[ii][jj]){
				out[idx++] = -1;
				out[idx++] = ii;
				out[idx++] = jj;
				check_edges[ii][jj] = 0;
				check_edges[jj][ii] = 0;
				num_trips++;
			}
		}
	}

	cout << num_trips << endl;
	len_idx = 0;
	len[len_idx] = 0;
	for(int i=1;i<idx;i++){
		if(out[i] != -1)
			len[len_idx]++;
		else{
			len[++len_idx] = 0;
		}
	}

	//assert(len[0]-1 >= 0);
	cout << len[0]-1 << " ";
	int j = 1;
	for(int i=1;i<idx;i++){
		if(out[i] != -1)
			cout << out[i] << " ";
		else{
			cout << endl;
			//assert(len[j]-1 >= 0);
			cout << len[j++]-1 << " ";
		}
	}
	cout << endl;

	for(int ii=0; ii<n; ii++){
		for (int jj=0; jj < n; ++jj){
			if(check_edges[ii][jj])
				cout << "not covered: " << ii << " " << j << endl;
			check_edges[ii][jj] = 0;
		}
	}
	
	for(int i=1;i<idx-1;i++){
		if( (out[i] != -1) && (out[i+1] != -1) ){
			check_edges[out[i]][out[i+1]] = 1;
			check_edges[out[i+1]][out[i]] = 1;
		}
	}

	for(int ii=0; ii<n; ii++)
		for (int jj=0; jj<n; ++jj){
			if(edges[ii][jj] && (check_edges[ii][jj] != 1));
				//while(1){

				//}
		}

}

void solve(){
	for(int i=0; i<n; i++){
		if(connected[i] == 0){
			dfs(i, 0);
		}
		else if(connected[i] == 1){
			dfs(i, 1);
		}
	}
	numTrips();
}

void print(int e, int t, int c){
	if(e){
		cout << "edges:\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << edges[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	if(t){
		cout << "trip:\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << trip[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	if(c){
		cout << "connected:\n";
		for(int i=0;i<n;i++){
			cout << connected[i] << " ";
		}
		cout << endl;
	}
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> pts[i][0] >> pts[i][1];
	string s;
	
	for(int i=0;i<n;i++){
		cin >> s;
		for(int j=0;j<n;j++){
			if(s[j] == 'N')
				edges[i][j] = 0;
			else{
				edges[i][j] = 1;
				m++;
			}
			check_edges[i][j] = edges[i][j];
			trip[i][j] = 0;
		}
		connected[i] = 0;
	}
	m /= 2;
	solve();
//	print(1,1,1);

	return 0;
}