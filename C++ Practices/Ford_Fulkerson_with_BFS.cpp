#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

#define V 8

bool BFS(int graph[V][V], int s, int t, int parent[V]){
  bool visited[V];
  memset(visited,0,sizeof(visited));

  queue <int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v = 0; v<V; v++){
      if(visited[v] == false && graph[u][v]>0){
	q.push(v);
	visited[v] = true;
	parent[v] = u;
      }
    }
  }

  return (visited[t] == true);
}

int Ford_Fulkerson(int graph[V][V], int s,int t){
  int parent[V];
  int rgraph[V][V];

  for(int u=0;u<V;u++)
    for(int v=0;v<V;v++)
    rgraph[u][v] = graph[u][v];

  int max_flow = 0;

  while(BFS(rgraph, s, t, parent)){
    
    int min_elem = INT_MAX;
    for(int v=t; v != s; v = parent[v]){
      int u = parent[v];
      min_elem = min(min_elem,rgraph[u][v]);
    }

    for(int v=t; v != s; v = parent[v]){
      int u = parent[v];
      rgraph[u][v] -= min_elem;
      rgraph[v][u] += min_elem;
    }
    max_flow += min_elem;
  }
  return max_flow;
}

int main(){
  /*  int graph[V][V] = { { 0, 16, 13, 0 , 0 , 0 },
		      { 0, 0 , 10, 12, 0 , 0 },
		      { 0, 4 , 0 , 0 , 14, 0 },
		      { 0, 0 , 9 , 0 , 0 , 20},
		      { 0, 0 , 0 , 7 , 0 , 4 },
		      { 0, 0 , 0 , 0 , 0 , 0 }
                    };
  */

  int graph[V][V] = { { 0, 10, 5 , 15, 0 , 0 , 0 , 0 },
		      { 0, 0 , 4 , 0 , 9 , 15, 0 , 0 },
		      { 0, 0 , 0 , 4 , 0 , 8 , 0 , 0 },
		      { 0, 0 , 0 , 0 , 0 , 0 , 16, 0 },
		      { 0, 0 , 0 , 0 , 0 , 15, 0 , 10},
		      { 0, 0 , 0 , 0 , 0 , 0 , 15, 10},
		      { 0, 0 , 6 , 0 , 0 , 0 , 0 , 10},
		      { 0, 0 , 0 , 0 , 0 , 0 , 0 , 0 },
                    };

  cout << "Max-Flow = " << Ford_Fulkerson(graph, 0, 7) <<"\n\n";  
  return 0;
}
