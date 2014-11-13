#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL dp[5010];

LL process(string s, int st){
	LL ret = 0;

	if(st>=s.size())
		return 0;

	if(s.size()-st==1){
		if(s[st]!='0')
			dp[st] = 1;
		else
			dp[st] = 0;
		return dp[st];
	}

	if(dp[st]!=0)
		return dp[st];

	if( !(st+1<s.size() && s[st+1]=='0') )
		ret = process(s,st+1);

	if(s[st]!='0' && st+1!=s.size()){
		int num = (int)(s[st]-'0');
		num *= 10;
		num += (int)(s[st+1]-'0');
		if(num<=26){
			if(st+2==s.size())
				ret += 1;
			else{
				if( !(st+2<s.size() && s[st+2]=='0') )
					ret += process(s,st+2);
			}
		}
	}

	dp[st] = ret;
	return ret;
}

int main(){
	string s;
	while((cin>>s) && s!="0"){
		memset(dp,0,sizeof(dp));
		int st = 0, ed = s.size()-1;

		bool correct_ip = true;

		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				if(s[i-1]!='1' && s[i-1]!='2'){
					correct_ip = false;
					break;
				}
			}
		}
		if(correct_ip)
			cout << process(s,0) << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}