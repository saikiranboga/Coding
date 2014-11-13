#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) cout << n

int main(){
	string s;
	while(cin>>s){
		bool contains_ = (s.find("_")!=string::npos)?true:false;
		bool contains_caps = false;

		rep(i,s.sz)
		{
			if(s[i]>='A' && s[i]<='Z')
			{
				contains_caps = true;
				break;
			}
		}

		bool bad_eg = false;

		rep(i,s.sz-1)
		{
			/*
			// two consecutive caps
			if( (s[i]>='A' && s[i]<='Z') && (s[i+1]>='A' && s[i+1]<='Z') )
			{
				bad_eg = true;
			}
			*/
			// contains two consecutive _
			if( s[i]=='_' && s[i+1]=='_' )
			{
				bad_eg = true;
			}
		}

		//if(s=="ja_va" || s=="jaVa")
//			bad_eg = true;

		if( (bad_eg) || (contains_ && contains_caps) || (s[0]>='A'&&s[0]<='Z') || (s[0]=='_') || (s[s.sz-1]=='_') )
		{
			cout << "Error!\n";
		}
		else if(contains_)
		{
			rep(i,s.sz)
			{
				if(s[i]=='_')
				{
					if(i+1<s.sz)
						cout << (char)( (int)'A' + (int)(s[i+1]-'a') );
					i++;
				}
				else
				{
					cout << s[i];
				}
			}
			cout << endl;
		}
		else
		{
			cout << s[0];
			fu(i,1,s.sz-1)
			{
				if(s[i]>='A' && s[i]<='Z')
				{
					cout << "_" << (char)( (int)('a') + (int)(s[i]-'A') );
				}
				else
				{
					cout << s[i];
				}
			}
			cout << endl;
		}
	}
	return 0;
}