/*
ID: saikira2
PROG: checker
LANG: C++
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
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

ofstream fout ("checker.out");
ifstream fin ("checker.in");

int n;
int board[13][13];
bool col_used[13];
bool left_diag_used[26];
bool right_diag_used[26];
int col_pos[13];
int tot = 0;
void print(){
    forn(i, n-1){
        forn(j, n){
            if(board[i][j]){
                fout << j+1 << " ";
                break;
            }
        }
    }
    forn(j, n){
        if(board[n-1][j]){
            fout << j+1 << endl;
            break;
        }
    }
}

bool attack(int row, int col){
    forn(i, row){
        if( abs(row-i)==abs(col-col_pos[i]) )
            return true;
    }
    return false;
}

void check(int row){
    if(row==n){
        if(tot<3)
            print();
        tot++;
        return;
    }
    forn(i, n){
        //if( !col_used[i] && !attack(row, i) ){
        if( !col_used[i] && !right_diag_used[row+i] && !left_diag_used[row+n-i+1]){
            right_diag_used[row+i] = true;
            left_diag_used[row+n-i+1] = true;
            col_used[i] = true;
            col_pos[row] = i;
            board[row][i] = 1;
            check(row+1);
            board[row][i] = 0;
            col_pos[row] = -1;
            col_used[i] = false;
            right_diag_used[row+i] = false;
            left_diag_used[row+n-i+1] = false;
        }
    }
}

int main(){
    clock_t t1 ,t2;
    t1 = clock();
    fin >> n;
    forn(i, 26){
        left_diag_used[i] = false;
        right_diag_used[i] = false;
    }
    forn(i, n){
        col_used[i] = false;
        col_pos[i] = -1;
        forn(j, n){
            board[i][j] = 0;
        }
    }
    check(0);
    fout << tot << endl;
    t2 = clock();
    float diff = t2-t1;
    float sec = diff/CLOCKS_PER_SEC;
    cout << sec << endl;
    return 0;
}