#include<iostream>
using namespace std;
#include<cstdio>
int x[1001][2];
int b[1001][3];

void quicksort(int a[][3],int left,int right){
  int i = left,j = right;
  int pivot = a[(left+right)/2][0];
  int temp = 0;
  while (i<=j){
    while (a[i][0]<pivot) i++;
    while (a[j][0]>pivot) j--;
    if (i<=j){
      temp=a[i][0];
      a[i][0]=a[j][0];
      a[j][0]=temp;
      
      temp=a[i][1];
      a[i][1]=a[j][1];
      a[j][1]=temp;

      i++;
      j--;
    }
  }
  if (left<j)
    quicksort(a,left,j);
  if (right>i)
    quicksort(a,i,right);
}

void quicksort3(int a[][3],int left,int right)
{
  int i = left,j=right;
  int pivot=a[(left+right)/2][1];
  int temp = 0;
  while (i<=j)
    {
      while (a[i][1]<pivot) i++;
      while (a[j][1]>pivot) j--;
      if (i<=j)
	{
	  temp=a[i][1];
	  a[i][1]=a[j][1];
	  a[j][1]=temp;

	  i++;
	  j--;
	}
    }
  if (left<j)
    quicksort3(a,left,j);
  if (right>i) quicksort3(a,i,right);
}

void quicksort2(int left,int right)
{
  int i = left,j=right;
  int pivot=x[(left+right)/2][0];
  int temp = 0;
  while (i<=j)
    {
      while (x[i][0]<pivot) i++;
      while (x[j][0]>pivot) j--;
      if (i<=j)
	{
	  temp = x[i][0];
	  x[i][0] = x[j][0];
	  x[j][0] = temp;

	  temp = x[i][1];
	  x[i][1] = x[j][1];
	  x[j][1] = temp;
	  temp = b[x[i][1]][1];
	  b[x[i][1]][1] = b[x[j][1]][1];
	  b[x[j][1]][1] = temp;

	  i++;
	  j--;
	}
    }
  if (left<j)
    quicksort2(left,j);
  if (right>i)
    quicksort2(i,right);
}

int max(int a,int b)
{
  if(a>b)
    return a;
  else
    return b;
}
int min(int a,int b)
{
  if(a>b)
    return b;
  else
    return a;
}

int ans[100000]={0};
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);

    for(int i=0;i<n;i++){
      scanf("%d",&x[i][0]);
      b[i][0] = x[i][0];
      b[i][1] = i;
    }
    quicksort(b,0,n-1);
      int check=0;
      for(int i=0;i<n-1;i++){
	b[i][2]=check;
	if(b[i][0]==b[i+1][0])
	  check++;
	else
	  check=0;
      }
      b[n-1][2]=check;
      for(int j=n-1;j>=0;j--){
	check=b[j][2];
	j-=check;
	if(check!=0)quicksort3(b,j,j+check);
      }

      for(int i=0;i<n;i++)
	x[b[i][1]][1]=i;
      int count=0;
      int temp;
      int last=n;

      for(int j=n-1;j>=0;j--){

	check = min(b[j][2],k-2);	
	j -= check;
	if(check!=0)
	  quicksort3(b,j,j+check);
	while(b[j][1]!=j){
	  temp=b[j][1];
	  if(b[j][1]+k-1>=last){
	    temp=max(0,last-k);
	  }
	  ans[count]=temp+1;
	  
	  count++;

	  quicksort2(temp,temp+k-1);
	  if(count>5)break;
	  if(check!=0)quicksort3(b,j,j+check);
	}
	last=j;
      }
      
      printf("%d\n",count);
      int lim=count;

      for(int i=0;i<lim;i++)
	printf("%d ",ans[i]);
      if(lim!=0)
	cout<<endl;
  }  
}
