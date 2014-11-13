// A C++ program to find maximal Bipartite matching.
#include <iostream>
#include <string.h>
using namespace std;
 
int M,N;
bool bpGraph[200][200];

// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(int u, bool seen[], int matchR[])
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
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
// Returns maximum number of matching from M to N
int maxBPM()
{
    // An array to keep track of the applicants assigned to
    // jobs. The value of matchR[i] is the applicant number
    // assigned to job i, the value -1 indicates nobody is
    // assigned.
    int matchR[N];
 
    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));
    //for (int i = 0; i < N; ++i)
    //{
    //    matchR[i] = -1;
    //}
 
    int result = 0; // Count of jobs assigned to applicants
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));
 
        // Find if the applicant 'u' can get a job
        if (bpm(u, seen, matchR))
            result++;
    }
    return result;
}
 
// Driver program to test above functions
int main()
{
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        M = n,N = n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                bpGraph[i][j] = 0;
        int x,y;
        for(int i=0;i<m;i++){
            cin >> x >> y;
            bpGraph[x-1][y-1] = 1;
            bpGraph[y-1][x-1] = 1;
        }
        //cout << "Maximum number of applicants that can get job is " << maxBPM();
        if(n%2 != 0 || m < n/2)
            cout << "NO\n";
        else{
            if(maxBPM() == n)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
 
    return 0;
}