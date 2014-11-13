#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;

#define pb push_back
#define sz size()

#define LL long long int 

#define MAXN 300010
#define inf 10000000

int main(){
    LL n;
    cin >> n;
    if(n<=4){
        switch(n){
            case 1:
                cout << "0\n";
                break;
            case 2:
            case 3:
                cout << "1\n";
                break;
            case 4:
                cout << "0\n";
                break;
        }
    }
    else{
        LL x = 0;
        LL y = 2;
        LL sum = x+y;
        LL ct = 1;
        while(sum < n){
            x += 3;
            sum += (x+y);
        }
        if(sum==n)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}