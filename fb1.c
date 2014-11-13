#include<stdio.h>
#include<string.h>

void quicksort(int x[],int first,int last){
  int pivot,j,temp,i;
  
  if(first<last){
    pivot=first;
    i=first;
    j=last;
    while(i<j){
      while(x[i]<=x[pivot]&&i<last)
	i++;
      while(x[j]>x[pivot])
	j--;
      if(i<j){
	temp=x[i];
	x[i]=x[j];
	x[j]=temp;
      }
    }
    temp=x[pivot];
    x[pivot]=x[j];
    x[j]=temp;
    quicksort(x,first,j-1);
    quicksort(x,j+1,last);
	 
  }
}

int main(){
  int i,j,t,m,sum;
  char c[10];
  scanf("%d",&t);
  gets(c);
  for(m=1;m<=t;m++){
    char ar[500];
    int times[26]={0};
    sum = 0;
    gets(ar);
    for(i=0; i<strlen(ar); i++){
      j = ar[i];
      if(j>40 && j<91){
	j -= 'A';
	times[j] += 1;
      }
      else if(j>96 && j<123){
	j -= 'a';
      times[j] += 1;
      }
    }
    quicksort(times,0,25);
    i = 25;
    while(times[i]!=0 && i>=0){
      sum += times[i]*(i+1);
      i--;
    }
    printf("case #%d: %d\n",m,sum);
  }
  return 0;
}
