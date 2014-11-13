#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int check(vector<string> a){
	string s;
	for(int i=0;i<3;i++){
		s = a[i];
		if(s.find("machula")!=string::npos)
			return i;
	}
	return 2;
}

int stoi(string s){
	stringstream ss(s);
	int ret;
	ss >> ret;
	return ret;
}

int main(){
	int t;
	string op1, op2, res;
	string op;
	cin >> t;
	while(t--){
		cin >> op1 >> op >> op2 >> op >> res;

		vector<string> ops;
		ops.pb(op1);
		ops.pb(op2);
		ops.pb(res);

		int which_one = check(ops);
		int first, second, rs;
		switch(which_one){
			case 0:
				second = stoi(op2);
				rs = stoi(res);
				cout << rs-second << " + " << second << " = " << rs << endl;
				break;
			case 1:
				first = stoi(op1);
				rs = stoi(res);
				cout << first << " + " << rs-first << " = " << rs << endl;
				break;
			case 2:
				first = stoi(op1);
				second = stoi(op2);
				cout << first << " + " << second << " = " << first+second << endl;
				break;
		}
	}
	return 0;
}