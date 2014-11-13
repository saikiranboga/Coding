/*
ID: saikira2
PROG: beads
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
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

int main(){
	ofstream fout ("beads.out");
    ifstream fin ("beads.in");
	int n;
	string s;
	fin >> n >> s;

	int max_beads=0, max_idx=0;
	forn(cut, n){
		//fout << cut << endl;
		int no_b = 1;
		int pos = (cut-2+n)%n;
		char bead = s[(cut-1+n)%n];
		while( (no_b<n) && (bead=='w' || s[pos]==bead || s[pos]=='w') ){
			no_b++;
			if(bead=='w')
				bead = s[pos];
			pos = (pos-1+n)%n;
		}
		//fout << "left " << no_b << endl;
		int rem = n-no_b;
		int right_b = 1;
		pos = (cut+1+n)%n;
		bead = s[(cut+n)%n];
		while( (right_b<rem) && (bead=='w' || s[pos]==bead || s[pos]=='w') ){
			right_b++;
			if(bead=='w')
				bead = s[pos];
			pos = (pos+1+n)%n;
		}
		//fout << "right " << right_b << endl;
		if(rem > 0)
			no_b += right_b;
		if(no_b > max_beads){
			max_beads = no_b;
			max_idx = cut;
		}
	}
	fout << max_beads << endl;
	//fout << max_idx << endl;
	return 0;
}

/*
29
brbrrrbbbrrrrrbrrbbrbbbbrrrrb
29
rbbrrwrbbrrrbwrrrrrbrbrwwbbbr
*/