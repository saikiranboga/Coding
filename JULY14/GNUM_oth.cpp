#include <iostream>
#include<stdio.h>
#include <limits.h>
#include <string.h>
#include <queue>

using namespace std;

// Number of vertices in given graph
#define V 1010
#define MAXN (402*402)

int a[MAXN],b[MAXN],gcd1[MAXN],gcd2[MAXN],temp;

int graph[V][V];

int rGraph[V][V]; // Residual graph where rGraph[i][j] indicates
                  // residual capacity of edge from i to j (if there
                  // is an edge. If rGraph[i][j] is 0, then there is not)

/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(int rGraph[V][V], int vertices, int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<vertices; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}

// Returns tne maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int vertices, int s, int t)
{
    int u, v;

    memset(rGraph,0,sizeof(rGraph));

    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    for (u = 0; u < vertices; u++)
        for (v = 0; v < vertices; v++)
             rGraph[u][v] = graph[u][v];

    int parent[V];  // This array is filled by BFS and to store path

    int max_flow = 0;  // There is no flow initially

    // Augment the flow while tere is path from source to sink
    while (bfs(rGraph,vertices, s, t, parent))
    {
        // Find minimum residual capacity of the edhes along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Return the overall flow
    return max_flow;
}

int GCD(int a, int b)
{
    if(a<b)
        return GCD(b,a);

    if(b==0)
        return a;

    return GCD(b,a%b);
}

int main()
{
    int test,n,count1,count2,i,j;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        for(i=0;i<n;i++)
            scanf("%d",&b[i]);

        count1=0;
        count2=0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                temp=GCD(a[i],b[j]);

                if(temp!=1&&a[i]<b[j])
                    gcd1[count1++]=temp;

                else if(temp!=1&&b[j]<a[i])
                    gcd2[count2++]=temp;
            }
        }

        memset(graph, 0, sizeof(graph));

        for(i=0;i<count1;i++)
            graph[0][i+1]=1;

        for(i=0;i<count2;i++)
            graph[count1+i+1][count1+count2+1]=1;

        for(i=0;i<count1;i++)
        {
            for(j=0;j<count2;j++)
            {
                if(GCD(gcd1[i],gcd2[j])!=1)
                    graph[i+1][count1+j+1]=1;
            }
        }

        printf("%d\n",fordFulkerson(graph, count1+count2+2, 0, count1+count2+1));

    }

    return 0;
}
