#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define LL long long int

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

int main(){
    int m,n;
    cin >> m >> n;
    int A[m+1][n+1];
    int B[m+1][n+1];
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++){
            cin >> B[i][j];
            A[i][j] = 1;
        }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(B[i][j] == 0){
                for(int jj=1; jj<=n; jj++)
                    A[i][jj] = 0;
                for(int ii=1; ii<=m; ii++)
                    A[ii][j] = 0;
            }
        }
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(B[i][j] == 0){
                for(int jj=1; jj<=n; jj++)
                    A[i][jj] = 0;
                for(int ii=1; ii<=m; ii++)
                    A[ii][j] = 0;
            }
        }
    }

    bool okay = true;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(B[i][j] == 1){
                bool one_exists = false;
                for(int jj=1; jj<=n; jj++){
                    if( A[i][jj] == 1){
                        one_exists = true;
                        break;
                    }
                }
                for(int ii=1; !one_exists && ii<=m; ii++){
                    if( A[ii][j] == 1 ){
                        one_exists = true;
                        break;
                    }
                }
                if(!one_exists){
                    okay = false;
                    break;
                }
            }
        }
        if(!okay)
            break;
    }

    if(!okay){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++)
                cout << A[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}