#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  int nSize, nQueries;
  cin>>nSize>>nQueries;
  int r[nSize], c[nSize];
  for(int i = 0; i < nSize; r[i] = 0, c[i] = 0, i++);
  char strIn[11];
  int N, X;
  while(nQueries-- > 0)
    {
      cin>>strIn;
      cin>>N>>X;
      N--;
      if(strIn[0] == 'R')
	  r[N]+=X;
      else
	  c[N]+=X;
    }
  int nR = 0, nC = 0;
  for(int i = 0; i < nSize; i++)
    {
      if(r[i] > nR)
	nR = r[i];
      if(c[i] > nC)
	nC = c[i];
    }
  cout<<nR+nC<<endl;	
  return 0;
}
  
