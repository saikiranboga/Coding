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
    int n, k;
    cin >> n >> k;
    int lt = 1;
    int rt = n;
    for(int i=1; i<=k; i++){
        if(i%2==0){
            cout << rt << " ";
            rt--;
        }
        else{
            cout << lt << " ";
            lt++;
        }
    }
    for(int i=k+1; i<=n; i++){
        if( (k+1)%2==0){
            cout << lt << " ";
            lt++;
        }
        else{
            cout << rt << " ";
            rt--;
        }
    }
    cout << endl;
    return 0;
}