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
    LL n, m;
    cin >> n >> m;
    LL p = n/m;
    LL q = n%m;
    LL kmin = ((q*(p+1)*p)/2) + (((m-q)*p*(p-1))/2);
    LL kmax = ((n-m+1)*(n-m)/2);
    cout << kmin << " " << kmax << endl;
    return 0;
}