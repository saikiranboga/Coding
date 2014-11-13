#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define VII vector< vector<int> >
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

#define sz size()

#define LL long long int 

#define MAXN 300010
#define inf 200010

VII g;

bool comp(PII a, PII b){
    if(a.ff==b.ff)
        return a.ss<=b.ss;
    return a.ff <= b.ff;
}

bool pos = false;
int n;

void dfs(int u, int h){
    if(h==n)
        pos = true;
    for(int i=0; i<g[u].sz; i++)
        dfs(g[u][i], h+1);
    return;
}

int main(){

    cin >> n;

    g.resize(2*n);

    string names[n][2];
    string f, l;

    for(int i=0; i<n; i++){
        cin >> f >> l;
        names[i][0] = f;
        names[i][1] = l;
    }

    PII order[n];
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        order[x-1].ff = i;
        order[x-1].ss = x-1;
    }

    sort(order, order+n, comp);

    for(int i=0; i<n-1; i++){
        int u = order[i].ss;
        int v = order[i+1].ss;
        if(names[u][0] < names[v][0]){
            g[u].pb( v );
            //g[v].pb( u );
        }
        if(names[u][1] < names[v][0]){
            g[u+n].pb( v );
            //g[v].pb( u+n );
        }
        if(names[u][0] < names[v][1]){
            g[u].pb( v+n );
            //g[v+n].pb( u );
        }
        if(names[u][1] < names[v][1]){
            g[u+n].pb( v+n );
            //g[v+n].pb( u+n );
        }
    }

    // for(int i=0; i<2*n; i++){
    //     for(int j=0; j<g[i].sz; j++)
    //         cout << g[i][j] << " ";
    //     cout << endl;
    // }

    dfs( order[0].ss , 1);
    dfs( order[0].ss + n, 1 );

    if(pos)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}