#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <iterator>
#include <map>
#include <memory>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <cctype>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#define MOD 1000000007
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int x){   V = x; adj = new list<int>[V]; }
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs();
    void dfsUtil(int v,bool visited[],long long &c);
    long long power(long long n);
};
long long Graph :: power(long long n)
{
    if(n == 0 || n == 1)
        return ((long long) 2);
    long long temp = power((n>>1));
    if(n & 1)
        return ((((((long long) 2)*temp) % MOD)*temp) % MOD);
    return ((temp*temp) % MOD);
}

void Graph ::dfsUtil(int v,bool visited[],long long &c)
{
    visited[v] = true;
    c++;
    list<int> :: iterator i;
    for(i = adj[v].begin(); i != adj[v].end();++i)
    {
        if(visited[(*i)] == false)
            dfsUtil((*i),visited,c);
    }
    
}

void Graph::dfs()
{
    int i;
    bool visited[V];
    for(i=0;i<V;++i) visited[i] = false;
    long long count = 0;
    for(i=0;i<V;++i)
    { long long c = 0;
        if(visited[i] == false)
            dfsUtil(i,visited,c);
        if(c>=1)
        count += (c-1);
    }
    cout<<power(count)<<"\n";
}
void foo(Graph &g)
{
    g.dfs();
}
int main()
{
    int n,m,u,v;
    cin >> n >> m;
    Graph g(n+1);
    int i;
    for(i=0;i<m;++i)
    {
        cin >> u >> v;
        g.addEdge(u-1,v);
    }
    foo(g);
    return 0;
}
