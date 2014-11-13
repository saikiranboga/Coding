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

bool comp(PII a, PII b){
    if(a.ff == b.ff)
        return a.ss <= b.ss;
    return a.ff <= b.ff;
}

int main(){
    int n;
    cin >> n;
    PII exams[n];
    for(int i=0; i<n; i++)
        cin >> exams[i].ff >> exams[i].ss;
    sort(exams, exams+n, comp);

    int cur = min(exams[0].ff, exams[0].ss);
    for(int i=1; i<n; i++){
        if(exams[i].ss >= cur)
            cur = exams[i].ss;
        else
            cur = exams[i].ff;
    }
    cout << cur << endl;
    return 0;
}