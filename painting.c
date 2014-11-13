#include<stdio.h>
int main(){
  int n,i,j,count;
  char canv[50][50];
  scanf("%d",&n);
  char result[2500][5];
  for(i=0;i<n;i++){
    scanf("%s",&canv[i]);
  }
  count = 0;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(canv[i][j]== 'B'){
	result[count][0] = i+'0';
	result[count][1] = j+'0';
	result[count][2] = i+'0';
	result[count][3] = j+'0';
	result[count][4] = canv[i][j];
	count++;
      }
    }
  }
  printf("%d\n",count);
  for(i=0;i<count;i++){
    for(j=0;j<5;j++){
      printf("%c",result[i][j]);
      if(j != 4)
	printf(" ");
    }
    printf("\n");
  }
  return 0;
}
