#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<math.h>
using namespace std;
#define L long
#define LL long long
#define ULL unsigned long long
#define D double
#define LD long double
#define MOD 1000000007
#define G getchar_unlocked
#define f first
#define s second
#define MAX 10005
#define pb push_back
#define mp make_pair

//typedef vector<L> vl

LL gcd(LL a,LL b){return (b)?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return (a*b)/gcd(a,b);}
L lcm(L a,L b){return (a*b)/gcd(a,b);}
LL modpow(LL n ,LL k,LL mod)
{LL ans=1;while(k>0){if(k&1)ans=(ans*n)%mod;k>>=1;n=(n*n)%mod;}return ans%mod;}

L max(LL a,LL b){return (a>b)?a:b;}
L min(LL a,LL b){return (a<b)?a:b;}
LL abs(LL a,LL b){return (a>0)?a:-a;}

L R()
{
 bool minus = false;
 L result = 0;
 char ch;
 ch = G();
 while (true)
 {
  if (ch == '-')
   break;
 if (ch >= '0' && ch <= '9')
   break;
 ch = G();
}
if(ch == '-')
  minus = true;
else
  result = ch-'0';
while (true)
{
  ch = G();
  if (ch < '0' || ch > '9')
   break;
 result = result*10 + (ch - '0');
}
if (minus)
  return -result;
else
  return result;
}

int main()
{
  ios::sync_with_stdio(false);
  vector <pair<L,L> > P,Q;
  vector <L> A;
  L T,n,m,i,a,b,till,j,x;
  bool flag;
  T=R();
  //cin>>T;
  while(T--)
  {
   flag=true;
   n=R(),m=R();
   //cin>>n>>m;
   for(i=0;i<n;i++)
    x=R(),A.pb(x);
  for(i=0;i<m;i++)
  {
    a=R(),b=R();
    //cin>>a>>b;
    P.pb(mp(a,b));
  }
  sort(P.begin(),P.end());
  a=0,till=P[0].s;
  for(i=1;i<P.size();i++)
  {
    if(P[i].f<=till){
     till=max(till, P[i].s);
    }
   else
   {
     Q.pb(mp(P[a].f,till));
     a=i;
     till=P[i].s;
   }
 }
 Q.pb(mp(P[a].f,P[i-1].s));
   //for(i=0;i<Q.size();i++)
    //cout<<Q[i].f<<" "<<Q[i].s<<endl;
 for(i=0;i<n;i++)
   if(A[i]!=i+1)
   {
     for(j=0;j<Q.size();j++)
      if(Q[j].f<=A[i]&&Q[j].s>=A[i])
      {
       if((Q[j].f<=i+1)&&(Q[j].s>=i+1));
	   //do nothing
       else
        flag=false,i=n;
      j=Q.size();
    }
    if(j==Q.size())
      flag=false,i=n;
  }
  if(flag)
    cout<<"Possible\n";
  else
    cout<<"Impossible\n";
  P.clear(),Q.clear();
  A.clear();
}
return 0;
}