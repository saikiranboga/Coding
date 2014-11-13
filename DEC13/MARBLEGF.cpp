#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

long long int data[10000000];
long long int length;

void update(long long int idx, long long int val)
{
  while (idx <= length)
    {
      data[idx] += val;
      idx += (idx & -idx);
    }
}

long long int query(long long int idx)
{
  long long int sum=0;
  while (idx>0)
    {
      sum += data[idx];
      idx -= (idx & -idx);
    }
  return sum;
}

int main(){
  long long int n,q,value;
  cin >> n >> q;
  memset(data,0,sizeof(long long int)*(n+1));
  length = n;
  long long int i;

  for(i=1;i<=n;i++){
    cin >> value;
    update(i,value);
  }
  char qry;
  long long int l,m;
  for(i=0;i<q;i++){
    cin >> qry >> l >> m;
    switch(qry){
    case 'S':
      if(l != 0)
	cout << query(m+1)-query(l) << endl;
      else
	cout << query(m+1) << endl;
      break;	
    case 'G':
      update(l+1, m);
      break;
    case 'T':
      update(l+1, -m);
      break;
    }
  }
  return 0;
}
