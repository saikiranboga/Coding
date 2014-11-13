/*
ID: saikira2
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <sstream>
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


int Mx = 0;
string longestPal(char inp[], char s[], int pos[], int inp_l, int s_l){

    int max_len = 0;
    int l_i, r_i;
    //checking for odd length pals
    forn(i, s_l){
        int l = i-1;
        int r = i+1;
        while(l>=0 && r<s_l && s[l]==s[r]){
            l--;
            r++;
        }
        int len = (i-l-1)*2 + 1;
        if(len > max_len){
            max_len = len;
            l_i = l+1;
            r_i = r-1;
        }
    }

    //checking for even length pals
    forn(i, s_l-1){
        int l = i;
        int r = i+1;
        while(l>=0 && r<s_l && s[l]==s[r]){
            l--;
            r++;
        }
        int len = (i-l)*2;
        if(len > max_len){
            max_len = len;
            l_i = l+1;
            r_i = r-1;
        }
    }

    string ret = "";
    fori(i, pos[l_i], pos[r_i])
        ret += inp[i];

    Mx = max_len;
    return ret;
}

int main(){
	ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");
    
    std::stringstream buffer;
    buffer << fin.rdbuf();

    string data(buffer.str());

    //cout << data << endl;

    char inp[20010];
    char s[20010];
    int pos[20010];
    char c;
    int i = 0;
    int j = 0;
    
    int sz = data.size();

    forn(k, sz){
        inp[i++] = data[k];
        if(isalpha(data[k])){
            s[j] = tolower(data[k]);
            pos[j++] = i-1;
        }
    }

    //forn(k, j)
    //    cout << s[k];
    //cout << endl;

    string ans = longestPal(inp, s, pos, i, j);
    fout << Mx << endl;
    fout << ans << endl;

	return 0;
}