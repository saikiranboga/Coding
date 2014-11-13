#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define cin(n) scanf("%d",&n)
#include<algorithm>
#include<cstring>
#define ill long long
#define inf 1000000007 
#define pb push_back
using namespace std;
#define mod 1000000007
#define maxn 100008

ill min(ill a,ill b)
{
    return a<b?a:b;
}

ill max(ill a,ill b)
{
    return a>b?a:b;
}

ill nCr[207][207],dp[207][207],fact[207],sum[207];
vector<int>v;
ill ncr(int n,int k)
{
    if(k<0||n<k)
            return 0;
    if(k==0||n==k)
        return 1;

    if(nCr[n][k]!=-1)
        return nCr[n][k];

    return nCr[n][k]=(ncr(n-1,k)+ncr(n-1,k-1))%mod;
}
ill rec(int pos,int k)
{
    if(k<0)
        return 0;

    if(pos==v.size())
    {
        if(k>=0)
            return 1;
        return 0;
    }
    if(dp[pos][k]!=-1)
        return dp[pos][k];

    ill ret=0;
    if(pos==0)
        return dp[pos][k]=(fact[v[pos]]*rec(pos+1,k-1))%mod;

    ret=(ncr(sum[pos]+v[pos]-1,sum[pos]-1)*rec(pos+1,k))%mod;
    ret=(ret*fact[v[pos]])%mod;


    ill ret1=(v[pos]*(ncr(sum[pos]+v[pos]-1,sum[pos])*rec(pos+1,k-1))%mod)%mod;
    ret1=(ret1*fact[v[pos]-1])%mod;

    return dp[pos][k]=(ret+ret1)%mod;
}


int main()
{
    int n,t,m,i,j,k,l,q;
    cin(t);
    
    fact[0]=1LL;
    for(i=1;i<=200;i++)
        fact[i]=(fact[i-1]*i)%mod;

    memset(nCr,-1,sizeof(nCr));

    while(t--)
    {
        cin(n);cin(k);
        
        int c[207];
        memset(c,0,sizeof(c));
        
        for(i=0;i<n;i++)
        {
            cin(q);
            c[q]++;
        }

        memset(dp,-1,sizeof(dp));

        v.clear();
        for(i=200;i>0;i--)
        {
            if(c[i])
                v.pb(c[i]);
        }
        memset(sum,0,sizeof(sum));

        for(i=1;i<v.size();i++)
            sum[i]=sum[i-1]+v[i-1];

        cout<<rec(0,k)<<"\n";
    }
    return 0;
}
