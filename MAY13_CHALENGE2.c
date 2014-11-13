#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUM_LETTERS 26

int main()
{
  int T,N,H,P,i,j;
  P = 1306;
  scanf("%d %d %d",&T,&N,&H);
  while(T--){

    for(i=0;i<N;i++){

      for(j=0;j<(8+(i+H+P)%4);j++){
	char c = 97 + (i+j+(H*(i+j-H))+P)%NUM_LETTERS;
	printf("%c",c);
      }
      printf("\n");

    }
    fflush(stdout);
    scanf("%d",&P);
  }
  return 0;
}
