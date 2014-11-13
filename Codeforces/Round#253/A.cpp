#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main(){
	char str[1020];
	gets(str);

	int sz = strlen(str);

	char c;
	int freq[26];
	
	memset(freq, 0, sizeof(freq));

	int ans = 0;

	for(int i=0;i<sz;i++){
		c = str[i];
		if(c>='a' && c<='z'){
			if(freq[c-'a']==0){
				ans++;
				freq[c-'a']++;
			}
		}
	}

	cout << ans << endl;


	return 0;
}