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

bool okay(int ar[4]){
    sort(ar, ar+4);
    int sum = ar[0] + ar[1] + ar[2] + ar[3];
    int sum2 = ar[1] + ar[2];
    if( sum%4!=0 )
        return false;
    if( sum2%2!=0 )
        return false;
    int mean = sum/4;
    int med = sum2/2;
    if(mean != med)
        return false;
    if(mean != ar[3]-ar[0])
        return false;
    return true;
}

void solve3(int a[]){
    int d1 = a[0]+a[1]-a[2];
    int ar1[4] = {a[0],a[1],a[2],d1};
    if( d1>0 && okay(ar1) ){
        cout << "YES\n";
        cout << d1 << endl;
    }
    else{
        int d2 = a[0]+a[2]-a[1];
        int ar2[4] = {a[0],a[1],a[2],d2};
        if(d2>0 && okay(ar2)){
            cout << "YES\n";
            cout << d2 << endl;
        }
        else{
            int d3 = a[1]+a[2]-a[0];
            int ar3[4] = {a[0],a[1],a[2],d3};
            if(d3>0 && okay(ar3)){
                cout << "YES\n";
                cout << d3 << endl;
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return;
}

void solve2(int a[]){
    if(3*a[0]==a[1]){
        int ar[4] = {a[0],a[1],1,1};
        int sum = a[0]+a[1];
        for(int i=1; i<=1010; i++){
            ar[0]=a[0], ar[1]=a[1], ar[2]=i, ar[3]=sum-i;
            if(ar[3]>0 && okay(ar)){
                cout << "YES\n";
                cout << i << "\n" << sum-i << endl;
                return;
            }
        }
    }
    int d = 3*a[0];
    int c = a[0]+d-a[1];
    int arr[4] = {a[0],a[1],c,d};
    if(okay(arr)){
        cout << "YES\n";
        cout << c << "\n" << d << endl;
        return;
    }
    if( (a[0]+a[1])%4 == 0 && (a[0]+a[1])/4){
        int x = (a[0]+a[1])/4;
        int y = 3*x;
        int ar[4] = {a[0],a[1],x,y};
        if(okay(ar)){
            cout << "YES\n";
            cout << x << "\n" << y << endl;
            return;
        }
    }

    if( a[1]%3==0 && a[1]/3 ){
        int x = a[1]/3;
        int y = 4*x - a[0];
        int ar[4] = {a[0],a[1],x,y};
        if(okay(ar)){
            cout << "YES\n";
            cout << x << "\n" << y << endl;
            return;
        }
    }

    cout << "NO\n";
    return;
}

void solve1(int a[]){
    int x, y;
    for(int i=1; i<=1000000; i++){
        if( (a[0]+i)%4==0 && (a[0]+i)/4 ){
            x = (a[0]+i)/4;
            y = 3*x;
            int ar[4] = {a[0],i,x,y};
            if(okay(ar)){
                cout << "YES\n";
                cout << i << "\n" << x << "\n" << y << endl;
                return;
            }
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    if(n==4){
        if(okay(a))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else if(n==3)
        solve3(a);
    else if(n==2)
        solve2(a);
    else if(n==1)
        solve1(a);
    else if(n==0)
        cout << "YES\n1\n1\n3\n3\n";
    return 0;
}