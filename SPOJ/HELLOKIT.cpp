#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int n;
	while( (cin>>s) && s!="." ){
		cin >> n;
		string orig = s;
		for(int i=2;i<=n;i++)
			s.append(orig);
		int cR = 0, totL = s.size();
		int start;
		for(int i=0;i<orig.size();i++){
			start = i;
			for(int j=0;j<totL;j++)
				cout << s[(j+start)%totL];
			cout << endl;
		}
	}
	return 0;
}