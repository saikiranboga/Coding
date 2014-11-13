#include<stdio.h>
#include<string.h>
int main(){
  int i,j,n,q;
  int m,p;
  char query[7];
  int max = 0;
  scanf("%d%d",&n,&q);
  int array[n][n];
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      array[i][j] = {0};
    }
  }
  for(i=1;i<=q;i++){
    scanf("%s",&query);
    if(strcmp(query,"RowAdd")==1){
      scanf("%d%d",&m,&p);
      for(j=0;j<n;j++){
	array[m-1][j] += p;
	if(array[m-1][j] > max){
	  max = array[m-1][j];
	}
      }
    }else{
      scanf("%d%d",&m,&p);
      for(j=0;j<n;j++){
	array[j][m-1] += p;
	if(array[j][m-1] > max){
	  max = array[j][m-1];
	}
      }
    }
  }
  printf("%d\n",max);
  return 0;
}
