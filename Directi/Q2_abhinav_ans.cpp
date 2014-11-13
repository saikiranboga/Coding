#include <iostream>
#include <vector>
using namespace std;

vector<long long>res[2];
long long a[91],mx[92];


void cal(long long n,int f)
{
	if(n==0)
		return;
	long long k=0;
	int i=0;
	while(mx[i]<n) i++;
	res[f].push_back(a[i]);
	if(a[i]>n)
	  cal(a[i]-n,(f+1)%2);
	else
	  cal(n-a[i],f);	  	
}

int main()
{
	int i,j;
	long long k=500000;
	k=k*k*k;
	a[0]=mx[0]=1,mx[1]=a[1]=3;
	i=2;
	while(a[i-2]+2*a[i-1]<=k)
	{
		a[i]=a[i-2]+2*a[i-1];
		mx[i]=a[i]+mx[i-2];
		i++;
	}
	cin>>k;
	cal(k,0);
	for(j=0;j<2;j++)
	{
		for(i=res[j].size()-1;i>=0;i--)
		  	cout<<res[j][i]<<endl;
		cout<<endl;
	}	
	return 0;
}