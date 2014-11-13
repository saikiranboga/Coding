#include<iostream>
#include<cmath>
#include<cstdio>
#include<string.h>
using namespace std;
int mod_pow(int base,int expo,int mod)
{
   if(base==0 && expo==0)
       if(mod==1)
       return 0;
       else
       return 1;
int res=1;
while(expo>0)
{
if(expo%2==1)
res=(res*base)%mod;
expo=expo/2;
base=(base*base)%mod;
} 
return res;  
}
int main()
{
int t,upper,d,n,m;
scanf("%d",&t);
while(t--)
{
scanf("%d %d %d %d",&upper,&d,&m,&n);
if(upper == 0)
	printf("1\n");
else{
	int i,j,k,temp=0,val[n],r,ans,n1;
	memset(val,0,sizeof(val));
	if(upper<=n)
		n1=upper;
	else
		n1=n;
	for(i=0;i<=n1;i++)
		for(j=0;j<=n1;j++)
			for(k=0;k<=n1;k++)
			{
				if((mod_pow(i,d,n)+mod_pow(j,d,n)+mod_pow(k,d,n))%n==m){
					temp++;
				}
				if(i==j && j==k)
					val[i]=temp;
			}
	printf("%d \n",val[n1]);
}
}
return 0;
}
 