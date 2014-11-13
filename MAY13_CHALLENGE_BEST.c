#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char rand_char(){
  return (char)( (rand() % 26) + 97);
}
 
int main()
{
  setvbuf(stdin, NULL, _IOFBF, 32768);
  setvbuf(stdout, NULL, _IOFBF, 32768); 

  srand(rand()+time(NULL));
  int T,N,H,i,j,score=0,new_score=-1;
  scanf("%d%d%d",&T,&N,&H);

  char passwords[200][13];
  int honey_server[200] = {0};

  for(i=0;i<N;i++){
    int len = rand()%5 + 8;
    for(j = 0; j < len; j++){
      passwords[i][j] = rand_char();
    }
    passwords[i][j] = '\0';    
  }

  int p1,p2,p3;
  char temp[13];

  while(T--){

    p1 = (int)(rand()%N);
    while(honey_server[(p1)%(N)] == 1 ){
      p1 = (++p1)%(N);
    }

    p2 = (int)(rand()%N);
    while( (honey_server[(p2)%(N)] == 1 ) || (p1 == p2)){
      p2 = (++p2)%(N);
    }

    strcpy(temp,passwords[p1]);
    strcpy(passwords[p1],passwords[p2]);
    strcpy(passwords[p2],passwords[p3]);
    strcpy(passwords[p3],temp);

    for(i=0;i<N;i++){
      printf("%s\n",passwords[i]);
      fflush(stdout);
    }

    scanf("%d",&new_score);

    if(new_score < score){
      strcpy(temp,passwords[p3]);
      strcpy(passwords[p3],passwords[p2]);
      strcpy(passwords[p2],passwords[p1]);
      strcpy(passwords[p1],temp);
    }
    else if(new_score == score){
      honey_server[p1] = 1;
      honey_server[p2] = 1;
      honey_server[p3] = 1;
    }
    else{
      score = new_score;
    }
  }
  return 0;
}
