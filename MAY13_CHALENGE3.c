#include <stdio.h>
#include <stdlib.h>

void quicksort(int x[],int index[],int first,int last){
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

	temp = index[i];
	index[i] = index[j];
	index[j] = temp;
      }
    }
    temp=x[pivot];
    x[pivot]=x[j];
    x[j]=temp;

    temp = index[pivot];
    index[pivot] = index[j];
    index[j] = temp;

    quicksort(x,index,first,j-1);
    quicksort(x,index,j+1,last);
	 
  }
}

char rand_char(){
  return (char)((rand() % 26) + 97);
}

int main()
{
  srand(0);

  int T,N,H,i,j,score,k;
  int _26scores[26],index[26];
  int len = 8;
  char pass[13];

  scanf("%d%d%d",&T,&N,&H);

  for(k = 0;k<T; k++){

    if(k<26){
      for(i=0;i<N;i++){
	for(j=0;j<8;j++)
	  printf("%c",(k+97));
	printf("\n");
      }
      fflush(stdout);
      scanf("%d",&_26scores[k]);
      index[k] = k;
    }

    if(k == 26){
      quicksort(_26scores,index,0,25);
      for(j = 0; j < len; j++){
	//	pass[j] = (char)(97 + index[25-(j/2)]);
	char c = (char)(97 + index[25]);
	pass[j] = c;
      }
      pass[j] = '\0';
    }

    if(k >= 26){
      for(i=0;i<N;i++){
	printf("%s\n",pass);
	fflush(stdout);
      }
      scanf("%d",&score);
    }
  }
  return 0;
}
