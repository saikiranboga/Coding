#include <stdio.h>
#include <stdlib.h>

char rand_char(){
  return (char)( (rand() % 26) + 97);
}

int main()
{
  srand(0);
  int T,N,H,i,j,score;
  scanf("%d%d%d",&T,&N,&H);
  while(T--){
    for(i=0;i<N;i++){
      int len = rand()%5 + 8;
      char pass[13];
      for(j = 0; j < len; j++){
	pass[j] = rand_char();
      }
      pass[j] = '\0';
      printf("%s\n",pass);
      fflush(stdout);
    }
    scanf("%d",&score);
    srand(rand());
  }
  return 0;
}
