#include <iostream>
#include <vector>
using namespace std;
int l,vw[10003],n,v,dp[65][65],in[64][10001];
vector<int>lst[6];

void cal()
{
	int i,j,k,p,q;
	for(i=0;i<n;i++)
	 in[0][i]=0;	
	// calculating friend id's for each possible filter
	for(i=1;i<(1<<l);i++)
	{
		for(j=0;j<n;j++) in[i][j]=0;
		k=(i-1)&i;
		for(j=0;j<n;j++) in[i][j]=in[k][j];
		k=i^k;
		for(j=0;j<l;j++) 
		 if(k&(1<<j))
		 {
		 	for(k=0;k<lst[j].size();k++)
		 	 in[i][lst[j][k]]=1;
		 	break; 
		 } 
	}			
	// checking for all possible combinations of included and excluded filters
	for(i=0;i<(1<<l);i++)
	{
		for(j=0;j<(1<<l);j++)
		{
			for(k=0;k<v;k++)	
			  if(in[j][vw[k]] || (in[i][vw[k]]==0 && i!=0))
			  {
			  	dp[i][j]=1;
			  	break;
			  }	
		}
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::ios_base::sync_with_stdio(false);
    int i,j,k,tmp,p,res=0,r[10003];
    
    
    cin>>n;
    cin>>v;
    for(i=0;i<n;i++)
        r[i]=vw[i]=0;
    for(i=0;i<v;i++)
    {
    	cin>>vw[i];
    }
    cin>>l;
    for(i=0;i<l;i++)
    {
        cin>>k;
        for(j=0;j<k;j++)
        {
            cin>>p;
            lst[i].push_back(p);
        }
    }
    cal();
    cin>>p;
    int inc,exc;
    res=0;
    for(i=0;i<p;i++)
    {
    	inc=0,exc=0;
        cin>>k;
        for(j=0;j<k;j++)
        {
            cin>>tmp;
            inc=inc|(1<<tmp);   
        }
        cin>>k;
        for(j=0;j<k;j++)
        {
            cin>>tmp;
            exc=exc|(1<<tmp);
        }
        res=res+dp[inc][exc];
    }
    cout<<res<<endl;
            
    return 0;
}