/*
ID: saikira2
PROG: transform
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

int main(){
	ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n;
    fin >> n;
    char before[n][n];
    char after[n][n];
    string line;

    // reading matrix before transformation
    forn(i,n){
        fin >> line;
        forn(j,n){
            before[i][j] = line[j];
        }
    }

    // reading matrix after transformation
    forn(i,n){
        fin >> line;
        forn(j,n){
            after[i][j] = line[j];
        }
    }

    //cout << "got both matrices\n";

    //checking for #1
    int flag = 1;
    forn(i,n){
        forn(j,n){
            if(before[i][j]!=after[j][n-1-i]){
                flag = 0;
                break;
            }
        }
    }

    if(flag){
        fout << 1 << endl;
        return 0;
    }

    //checking for #2
    flag = 1;
    forn(i,n){
        forn(j,n){
            if(before[i][j]!=after[n-1-i][n-1-j]){
                flag = 0;
                break;
            }
        }
    }

    if(flag){
        fout << 2 << endl;
        return 0;
    }

    //checking for #3
    flag = 1;
    forn(i,n){
        forn(j,n){
            if(before[i][j]!=after[n-1-j][i]){
                flag = 0;
                break;
            }
        }
    }

    if(flag){
        fout << 3 << endl;
        return 0;
    }


    //checking for #4
    flag = 1;
    forn(i,n){
        forn(j,n){
            if(before[i][j]!=after[i][n-1-j]){
                flag = 0;
                break;
            }
        }
    }

    if(flag){
        fout << 4 << endl;
        return 0;
    }

    //checking for #5

    char reflect[n][n];

    forn(i,n){
        forn(j,n){
            reflect[i][n-1-j] = before[i][j];
        }
    }

    //checking for #1 in #5
    flag = 1;
    forn(i,n){
        forn(j,n){
            if(reflect[i][j]!=after[j][n-1-i]){
                flag = 0;
                break;
            }
        }
    }

    if(flag){
        fout << 5 << endl;
        return 0;
    }

    //checking for #2 in #5
    flag = 1;
    forn(i,n){
        forn(j,n){
            if(reflect[i][j]!=after[n-1-i][n-1-j]){
                flag = 0;
                break;
            }
        }
    }

    if(flag){
        fout << 5 << endl;
        return 0;
    }

    //checking for #3 in #5
    flag = 1;
    forn(i,n){
        forn(j,n){
            if(reflect[i][j]!=after[n-1-j][i]){
                flag = 0;
                break;
            }
        }
    }

    if(flag){
        fout << 5 << endl;
        return 0;
    }


    //end of check for #5

    //checking for #6
    flag = 1;
    forn(i,n){
        forn(j,n){
            if(before[i][j]!=after[i][j]){
                flag = 0;
                break;
            }
        }
    }

    if(flag){
        fout << 6 << endl;
        return 0;
    }


    fout << 7 << endl;

	return 0;
}

/*

@-@
---
-@@

*/