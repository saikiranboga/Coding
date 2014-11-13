#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

#define ll long long

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define ford(i, up, bot) for(int i = (up); i > (bot); --i)
#define fordi(i, up, bot) ford(i, up, bot-1)

#define pb push_back
#define mp make_pair

typedef pair<int, int> pt;

#define Max 1000010

char board[100][100];
int n;

bool check(){
	forn(i, n){
		forn(j, n){
			if(board[i][j]=='#')
				return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	string str;
	int num_hsh = 0;
	forn(i, n){
		cin >> str;
		forn(j,n){
			board[i][j] = str[j];
			if(board[i][j]=='#')
				num_hsh++;
		}
	}

	if( num_hsh%5 != 0){
		cout << "NO\n";
	}
	else{

		while(check()){
			forn(i,n){
				forn(j,n){
					if(board[i][j]=='#'){

						if(i-1>=0 && board[i-1][j]=='#' && i+1<n && board[i+1][j]=='#' && j-1>=0 && board[i][j-1]=='#' && j+1<n && board[i][j+1]=='#'){
							//check for middle #
							board[i][j] = '.';
							board[i-1][j] = '.';
							board[i+1][j] = '.';
							board[i][j-1] = '.';
							board[i][j+1] = '.';
						}
						else if(j+1<n && board[i][j+1]=='#' && j+2<n && board[i][j+2]=='#' && i-1>=0 && board[i-1][j+1]=='#' && i+1<n && board[i+1][j+1]=='#'){
							//check for left #
							board[i][j] = '.';
							board[i][j+1] = '.';
							board[i][j+2] = '.';
							board[i-1][j+1] = '.';
							board[i+1][j+1] = '.';
						}
						else if(i+1<n && board[i+1][j]=='#' && i+2<n && board[i+2][j]=='#' && j-1>=0 && board[i+1][j-1]=='#' && j+1<n && board[i+1][j+1]=='#'){
							//check for top #
							board[i][j]=='.';
							board[i+1][j]=='.';
							board[i+2][j]=='.';
							board[i+1][j-1]=='.';
							board[i+1][j+1]=='.';
						}
						else if(j-1>=0 && board[i][j-1]=='#' && j-2>=0 && board[i][j-2]=='#' && i-1>=0 && board[i-1][j-1]=='#' && i+1<n && board[i+1][j-1]=='#'){
							//check for right #
							board[i][j]=='.';
							board[i][j-1]=='.';
							board[i][j-2]=='.';
							board[i-1][j-1]=='.';
							board[i+1][j-1]=='.';
						}
						else if(i-1>=0 && board[i-1][j]=='#' && i-2>=0 && board[i-2][j]=='#' && j-1>=0 && board[i-1][j-1]=='#' && j+1<n && board[i-1][j+1]=='#'){
							//check for bottom #
							board[i][j] = '.';
							board[i-1][j] = '.';
							board[i-2][j] = '.';
							board[i-1][j-1] = '.';
							board[i-1][j+1] = '.';
						}
						else{
							cout << "NO\n";
							return 0;
						}
					}
				}
			}
		}
		cout << "YES\n";
	}

	return 0;
}