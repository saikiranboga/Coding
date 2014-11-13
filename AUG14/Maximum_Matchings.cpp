// A C++ program to find maximal Bipartite matching.
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
 
#define MAXM 10
#define MAXN 110

// M is number of applicants and N is number of jobs
int M, N;
 
// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(bool bpGraph[MAXM][MAXN], int u, bool seen[], int matchR[])
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        // If applicant u is interested in job v and v is
        // not visited
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true; // Mark v as visited
 
            // If job 'v' is not assigned to an applicant OR
            // previously assigned applicant for job v (which is matchR[v]) 
            // has an alternate job available. 
            // Since v is marked as visited in the above line, matchR[v] 
            // in the following recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
// Returns maximum number of matching from M to N
int maxBPM(bool bpGraph[MAXM][MAXN], int matchR[])
{
    // matchR[N] is an array to keep track of the applicants 
    // assigned to jobs. The value of matchR[i] is the applicant
    // number assigned to job i, the value -1 indicates nobody
    // is assigned.
 
    int result = 0; // Count of jobs assigned to applicants
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));
 
        // Find if the applicant 'u' can get a job
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}
 
// Driver program to test above functions
int main()
{
    // Let us create a bpGraph shown in the above example

    scanf("%d",&M);
    N = 110;
    bool bpGraph[MAXM][MAXN];
    memset(bpGraph, false, sizeof(bpGraph));
    int x;
    char c;
    for(int i=0;i<M;i++){
        do{
            scanf("%d%c",&x,&c);
            bpGraph[i][x+9] = true;
        }while(c!='\n');
    }

    int matchR[N];
    for(int i=0;i<N;i++)
        matchR[i] = -1;
    int ans = 0;
    while( maxBPM(bpGraph, matchR) == M){
        for(int i=10;i<110;i++){
            if(matchR[i]==0)
                bpGraph[0][i] = false;
        }
        for(int i=0;i<N;i++)
            matchR[i] = -1;
        ans++;
    }
    cout << ans << endl;
    return 0;
}