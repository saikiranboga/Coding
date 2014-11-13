#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
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

int digs[1000010];

int genPalin(string buf){
	
	int sz = buf.size();
	memset(digs,0,sizeof(digs));
	forn(i, sz)
		digs[i] = (int)(buf[i]-'0');
	if(sz<2)
		return 0;
	int mid = (sz&1)?(sz/2):(sz/2-1);

	int l, r;
	if(sz&1)
		l = mid-1, r = mid+1;
	else
		l = mid, r = mid+1;
	
	while(l>=0 && digs[l]==digs[r])
		l--, r++;

	bool left_smaller = false;

	if(l<0)
		return 0;
	if(digs[l]<digs[r])
			left_smaller = true;
	while(l>=0)
		digs[r++] = digs[l--];

	if(left_smaller){
		int carry = 1;

		if(sz&1){
			l = mid-1, r = mid+1;
			digs[mid] += carry;
			carry = digs[mid]/10;
			digs[mid] = digs[mid]%10;
		}
		else
			l = mid, r = mid+1;

		while(l>=0){
			digs[l] += carry;
			carry = digs[l]/10;
			digs[l] = digs[l]%10;
			digs[r++] = digs[l--];
		}
	}

	return 0;
}

int main(){	
	int t,len;
	string buf;
	cin >> t;
	while(t--){
		cin >> buf;
		string buf2 = "";
		len = buf.size();
		int carry = false;

		if(buf[len-1]=='9'){
			buf2.pb('0');
			carry = true;
		}
		else{
			buf2.pb((char)(buf[len-1]+1));
			carry = false;
		}
		
		for(int i=len-2;i>=0;i--){
			if(buf[i]=='9'){
				if(carry==true){
					buf2.pb('0');
					carry = true;
				}
				else{
					buf2.pb('9');
					carry = false;
				}
			}
			else{
				if(carry==true){
					buf2.pb(  (char)(buf[i]+1) );
				}
				else{
					buf2.pb( buf[i] );
				}
				carry = false;
			}
		}
		if(carry==true){
			buf2.pb('1');
		}
		
		reverse(buf2.begin(),buf2.end());
		buf = buf2;
		len = buf.size();

		int len_changed = genPalin(buf);

		if(len_changed == 1)
			cout << 1;
		forn(i,len)
			cout << digs[i];
		cout << endl;
	}
	return 0;
}