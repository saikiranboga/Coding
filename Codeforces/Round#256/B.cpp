#include <iostream>
#include <cstring>
#include <string>
using namespace std;

typedef long long int lli;
#define mp make_pair

bool check(string txt, string s){
	int pos = -1;
    bool ok = true;
    for (int i = 0 ; ok && i != s.size() ; i++) {
        ok = (pos = txt.find(s[i], pos+1)) != string::npos;
    }
    if(ok)
    	return true;
    else
    	return false;
}

int main(){
	string s, t;
	cin >> s >> t;
	int s_freq[26], t_freq[26];
	
	memset(s_freq, 0, sizeof(s_freq));
	memset(t_freq, 0, sizeof(t_freq));

	for(int i=0;i<s.size();i++){
		s_freq[s[i]-'a']++;
	}
	for(int i=0;i<t.size();i++){
		t_freq[t[i]-'a']++;
	}

	//-1: not yet started
	//0: automaton
	//1: array
	//2: both
	//3: tree
	int req = -1;

	for(int i=0;i<26;i++){
		if(s_freq[i]<t_freq[i]){
			req = 3;
			break;
		}
	}

	bool all_equal = true;

	if(req!=3){
		for(int i=0;i<26;i++){
			if(s_freq[i]!=t_freq[i]){
				all_equal = false;
				break;
			}
		}
		if(all_equal){
			req = 1;
		}
	}

	if(req!=3 && req!=1){
		if(check(s,t)){
			req = 0;
		}
		else{
			req = 2;
		}
	}

	switch(req){
		case 0:
			cout << "automaton\n";
			break;
		case 1:
			cout << "array\n";
			break;
		case 2:
			cout << "both\n";
			break;
		case 3:
			cout << "need tree\n";
			break;
	}

	return 0;
}