#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

#define ulong unsigned long long
#define MOD 1000000007

ofstream fout ("snos_fkind.out");

int main(){
    ulong n = 8;
    cin >> n;
    ulong s1[n+1][n+1];
    memset(s1, 0, sizeof(s1));
    for(ulong i=0; i<=n; ++i)
        s1[i][0] = 0;
    s1[1][1] = 1;
    s1[0][0] = 1;

    for(ulong i=2; i<=n; i++){
        s1[i][1] = ( (i-1)*(s1[i-1][1]%MOD) )%MOD;
        for(ulong j=2; j<=i; j++){
            s1[i][j] = ( (s1[i-1][j-1]%MOD) + (i-1)*( s1[i-1][j]%MOD ) )%MOD;
        }
    }

    ulong s2[n+1][n+1];
    memset(s2, 0, sizeof(s2));
    for(ulong i=1; i<=n; i++){
        s2[i][1] = 1;
        s2[i][i] = 1;
    }
    s2[0][0] = 1;
    for(ulong i=2; i<=n; i++){
        for(ulong j=2; j<=i; j++){
            s2[i][j] = ( (s2[i-1][j-1]%MOD) + (j)*( s2[i-1][j]%MOD ) )%MOD;
        }
    }

    return 0;
}