#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stdlib.h>
#include <map>
#include <string.h>
#include <algorithm>
typedef long long int ll;
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main() {
	ios_base::sync_with_stdio(false);
	int n, m, temp, a, b, i, j, answer1=0, answer2=0, count;
	bool window[50001], visited[50001];
	vector<int> graph[50001];
	queue<int> q;
	queue<pair<int, int> > qq;
	memset(visited, 0, 50001*sizeof(bool));
	cin >> n >> m;
	for(i=0;i<n;++i) {
		cin>>temp;
		window[i] = temp;
	}
	for(i=0;i<m;++i) {
		cin>>a>>b;
		--a;--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(i=0;i<n;++i) {
		memset(visited, 0, 50001*sizeof(bool));
		if(window[i])
			count = 1;
		else
			count = 0;
		visited[i] = true;
		qq.push(make_pair(i, 0));
		while(!qq.empty() ) {
			pair<int, int> x = qq.front();
			if(window[x.first] && !x.second && x.first!=i) {
				count += 1;
				x.second = 1;
			}
			qq.pop();
			for(j=0; (!x.second) && ( j<graph[x.first].size() ) ;++j) {
				if(!visited[graph[x.first][j]]) {
					visited[graph[x.first][j]] = true;
					qq.push(make_pair(graph[x.first][j], x.second));
				}
			}
		} 
		if(count>1)
			answer2++;
	}
	
	memset(visited, 0, 50001*sizeof(bool));
	for(i=0;i<n;++i) {
		if(!visited[i]) {
			count=0;
			visited[i] = true;
			q.push(i);
			while(!q.empty()) {
				temp = q.front();
				if(window[temp])
					++count;
				q.pop();
				for(j=0;j<graph[temp].size();++j) {
					if(!visited[graph[temp][j]]) {
						visited[graph[temp][j]] = true;
						q.push(graph[temp][j]);
					}
				}
			}
			answer1 += ((count-1)*count)/2;
		}
	}
	cout<< answer1 << " " << answer2;
	return 0;
}