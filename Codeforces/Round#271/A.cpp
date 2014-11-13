#include <bits/stdc++.h>
#include <string.h>
using namespace std;

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

	string keyboard[3] = {"qwertyuiop","asdfghjkl;","zxcvbnm,./"};

	string type, s;
	char ans[110];
	cin >> type >> s;
	char cur;
	if(type == "L"){
		for(int i=0; i<s.sz; i++){
			cur = s[i];
			for(int ll=0; ll<3; ll++){
				for(int j=0; j<10; j++){
					if(keyboard[ll][j]==cur)
						ans[i] = keyboard[ll][j+1];
				}
			}
		}
	}
	else{
		for(int i=0; i<s.sz; i++){
			cur = s[i];
			for(int ll=0; ll<3; ll++){
				for(int j=0; j<10; j++){
					if(keyboard[ll][j]==cur)
						ans[i] = keyboard[ll][j-1];
				}
			}
		}
	}

	for(int i=0; i<s.sz; i++)
		cout << ans[i];
	cout << endl;

	return 0;
}