#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cmath>
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

int main(){
    ios_base::sync_with_stdio(false);
    int n, v;
    cin >> n;
    cin >> v;
    vector<int> viewed;
    int tmp;
    forn(i, v){
        cin >> tmp;
        viewed.pb(tmp);
    }

    int l;
    cin >> l;
    int list_size[l];
    vector<int> list[l];

    int excl[n][l];
    memset(excl, 0, sizeof(excl) );

    forn(i, l){
        cin >> list_size[i];
        forn(j, list_size[i]){
            cin >> tmp;
            list[i].pb(tmp);
            excl[tmp][i] = 1;
        }
    }

    int p;
    int compr = 0;
    cin >> p;
    forn(i, p){
        int in_sz, ex_sz;
        cin >> in_sz;
        int in[7];
        memset(in, 0, sizeof(in) );
        forn(j,in_sz){
            cin >> tmp;
            in[tmp] = 1;
        }

        cin >> ex_sz;
        int ex[7];
        memset(ex, 0, sizeof(ex) );
        forn(j,ex_sz){
            cin >> tmp;
            ex[tmp] = 1;
        }
        int check = 0;

        if(in_sz==0 && ex_sz==0){
            check = 1
        }
        if( !check && in_sz > 0){
            forn(k, v){
                int flag = 0;
                forn(j, in_sz){
                    if( excl[ viewed[k] ][ in[j] ]==1 ){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    compr++;
                    check = 1;
                    break;
                }
            }

        }
        if(!check && ex_sz > 0){
            int flag = 0;
            forn(j, v){
                forn(k, ex_sz){
                    if( excl[ viewed[j] ][ ex[k] ] == 1){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1)
                    break;
            }
            if(flag==1){
                compr++;
                //cout << "compr\n";
            }
        }
    }

    cout << compr << endl;

	return 0;
}