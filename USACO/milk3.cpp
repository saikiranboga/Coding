/*
ID: saikira2
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

#define ll long long

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define ford(i, up, bot) for(int i = (up); i > (bot); --i)
#define fordi(i, up, bot) ford(i, up, bot-1)

#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pt;

int visited[21][21][21];

vector<int> ans;
int A, B, C;

void dfs(int a, int b, int c){
    int AA, BB, CC;
    visited[a][b][c] = 1;
    if(a==0){
        ans.pb(c);
        //cout << a << " " << b << " " << c << endl;
    }
    AA = a;
    BB = b;
    if(a>0 && b<B){
        if(a >= B-b){
            a = a-(B-b);
            b = B;
        }
        else{
            b = b+a;
            a = 0;
        }
        if(!visited[a][b][c])
            dfs(a,b,c);
    }
    a = AA;
    b = BB;

    AA = a;
    CC = c;
    if(a>0 && c<C){
        if(a >= C-c){
            a = a-(C-c);
            c = C;
        }
        else{
            c = c+a;
            a = 0;
        }
        if(!visited[a][b][c])
            dfs(a,b,c);
    }
    a = AA;
    c = CC;

    BB = b;
    AA = a;
    if(b>0 && a<A){
        if(b >= A-a){
            b = b-(A-a);
            a = A;
        }
        else{
            a = a+b;
            b = 0;
        }
        if(!visited[a][b][c])
            dfs(a,b,c);
    }
    b = BB;
    a = AA;

    BB = b;
    CC = c;
    if(b>0 && c<C){
        if(b >= C-c){
            b = b-(C-c);
            c = C;
        }
        else{
            c = c+b;
            b = 0;
        }
        if(!visited[a][b][c])
            dfs(a,b,c);
    }
    b = BB;
    c = CC;

    CC = c;
    AA = a;
    if(c>0 && a<A){
        if(c >= A-a){
            c = c-(A-a);
            a = A;
        }
        else{
            a = a+c;
            c = 0;
        }
        if(!visited[a][b][c])
            dfs(a,b,c);
    }
    c = CC;
    a = AA;

    CC = c;
    BB = b;
    if(c>0 && b<B){
        if(c >= B-b){
            c = c-(B-b);
            b = B;
        }
        else{
            b = b+c;
            c = 0;
        }
        if(!visited[a][b][c])
            dfs(a,b,c);
    }
    c = CC;
    b = BB;
}

int main(){
	ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");

    fin >> A >> B >> C;

    forn(i, 21) forn(j, 21) forn(k, 21)
        visited[i][j][k] = 0;

    dfs(0,0,C);

    sort(ans.begin(), ans.end());

    int sz = ans.size();
    forn(i, sz-1)
        fout << ans[i] << " ";
    fout << ans[sz-1] << endl;
	return 0;
}