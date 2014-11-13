#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

#define V 1010
#define MAXN (402*402)

int a[MAXN],b[MAXN],gcd1[MAXN],gcd2[MAXN],temp;

struct MaximumFlowFordFulkerson {

    // runtime: O(E F), E = #edges, F = max flow values

    typedef struct edge {
        int v;
        int capacity; 
        int flow; // current amount allowed to flow
        int rev_index; // store its reversed edge's index
        edge(int v_, int c_, int f_, int rev) : v(v_), capacity(c_), flow(f_), rev_index(rev) {}
    } Edge;
 
    int N; // node from 0 to N - 1
    vector<vector<Edge> > maxFlowEdge;
    int mark;   // global variable for checking if a node is already visited
    vector<int> seen;  // status of each node

    MaximumFlowFordFulkerson(int numNode){
        N = numNode;
        maxFlowEdge = vector<vector<Edge> >(numNode);
        seen = vector<int>(numNode);
        mark = 0;
    }

    void addEdge(int from, int to, int cap){
        maxFlowEdge[from].push_back(Edge(to, cap, cap, maxFlowEdge[to].size()));
        maxFlowEdge[to].push_back(Edge(from, 0, 0, maxFlowEdge[from].size() - 1));
    }
 
    void resetFlow(){
        for(int i = 0; i < N; i++ ){
            seen[i] = false;
            int sz = maxFlowEdge[i].size();
            for(int j = 0; j < sz; j++ ){
                maxFlowEdge[i][j].flow = maxFlowEdge[i][j].capacity;
            }
        }
    }
 
    int findAugmentingPath(int at, int sink, int val){
        int sol = 0;
        seen[at] = mark;
        if (at == sink) return val;
        int sz = maxFlowEdge[at].size();
        for (int i = 0; i < sz; i++ ) {
            int v = maxFlowEdge[at][i].v;
            int f = maxFlowEdge[at][i].flow;
            if (seen[v] != mark && f > 0){
                sol = findAugmentingPath(v, sink, min(f, val));
                if (sol) {
                    maxFlowEdge[at][i].flow -= sol;
                    int rev = maxFlowEdge[at][i].rev_index;
                    maxFlowEdge[v][rev].flow += sol;
                    return sol;
                }
            }
        }
        return 0;
    }
 
    int getMaximumFlow(int S, int T){
        int res = 0;
        while(1){
            mark++;
            int flow = findAugmentingPath(S, T, 1000000000);
            if(flow == 0) break;
            else res += flow;
        }
        return res;
    }
};

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
    int t,n,count1,count2,i,j;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i=0;i<n;i++)
            cin >> a[i];

        for(i=0;i<n;i++)
            cin >> b[i];

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
