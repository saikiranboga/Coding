#include<cstdio>
#include<iostream>
int fre[25][100005];
int prime[]={ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
long long int mod_exp(long long int a,long long int b,long long int MOD)
{
if(a==0)
return 1;
long long int x = 1, y = a;
while(b > 0) {
if(b%2 == 1) {
x=(x*y);
if(x>MOD) x%=MOD;
}
y = (y*y);
if(y>MOD) y%=MOD;
b /= 2;
}
return x;
}
int main()
{
int N,T,x,L,R,M;
scanf("%d",&N);
for(int i=1;i<=N;i++)
{
scanf("%d",&x);
for(int j=0;j<25;j++)
{
while(x%prime[j]==0)
x=x/prime[j],fre[j][i]++;
fre[j][i]+=fre[j][i-1];
}
}
/*for(int i=1;i<=N;i++)
{
for(int j=0;j<=5;j++)
{
printf("%d ",fre[j][i]);
}
printf("\n");
}*/
scanf("%d",&T);
while(T--)
{
scanf("%d%d%d",&L,&R,&M);
long long res=1;
 
for(int i=0;i<=24;i++)
{
res=res*mod_exp(prime[i],(fre[i][R]-fre[i][L-1]),M)%M;
}
printf("%d\n",res);
}
}

/*
20
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
 */
