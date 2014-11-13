#include<iostream>
using namespace std;

/*
 * Can be easily modified for -ve array sum:
 * 		Currently, this program returns the +ve sum, only if atleast one of the element is +ve (>0)
 * 		So, if the overall sum is 0, there might not be any +ve number in the array at all.
 * 		In this case, the ans is actually the largest element in the array.
 * 		So, just one more linear scan will be required.
 */

int main()
{
	int arr[100];
	int N,T;
	int maxsofar;
	int maxhere;

	scanf("%d",&T);
	while(T--)
	{
			  scanf("%d",&N);
			  for(int i=0; i<N; i++)
			  scanf("%d",&arr[i]);
			  
			  maxsofar = 0;
			  maxhere = 0;
   			  for(int i=0; i<N; i++)
			  {
					maxhere = (maxhere+arr[i])>0?(maxhere+arr[i]):0;
					maxsofar = maxsofar>maxhere?maxsofar:maxhere;
			  }
			  cout<<maxsofar<<"\n";
	}
	
}