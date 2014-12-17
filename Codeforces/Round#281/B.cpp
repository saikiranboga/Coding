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
    int n;
    cin >> n;
    LL s1 = 0, s2 = 0;
    LL first[n], second[n];
    int i1,i2;
    i1 = i2 = 0;
    LL a;
    int greater = -1;
    int last = -1;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if(i==n-1){
            if(a>0)
                last = 0;
            else
                last = 1;
        }
        if(a > 0){
            first[i1] = a;
            i1++;
            s1 += a;
        }
        else{
            a = (-1LL * a);
            second[i2] = a;
            i2++;
            s2 += a;
        }
    }
    if(s1>s2)
        greater = 0;
    else if(s1 < s2)
        greater = 1;
    else{
        int lmin = min(i1, i2);
        for (int i = 0; i < lmin; ++i)
        {
            if(first[i]>second[i]){
                greater = 0;
                break;
            }
            else if(first[i]<second[i]){
                greater = 1;
                break;
            }
        }
        if(greater == -1){
            if(i1 > i2)
                greater = 0;
            else if(i1 < i2)
                greater = 1;
        }
        if(greater == -1)
            greater = last;
    }
    if(greater == 0)
        cout << "first\n";
    else
        cout << "second\n";
    return 0;
}