#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
char rand_char(){
  return (char)( (rand() % 26) + 97);
}
 
int main()
{
  setvbuf(stdin, NULL, _IOFBF, 32768);
  setvbuf(stdout, NULL, _IOFBF, 32768); 

  //  srand(rand()+time(NULL));
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

  int change,change2,change3,change4,change5;
  char old_pass[13];
  char old_pass2[13];
  char old_pass3[13];
  char old_pass4[13];
  char old_pass5[13];

  int server_no = 0;
  while(T--){
    if(honey_server[server_no%(N)] == 1){
      change = (++server_no)%(N);
    }
    else{
      change = server_no%(N);
    }
    strcpy(old_pass,passwords[change]);

    if(honey_server[(1+change)%(N)] == 1){
      change2 = (2+change)%(N);
    }
    else{
      change2 = (change+1)%(N);
    }

    strcpy(old_pass2,passwords[change2]);


    /*    if(honey_server[(1+change2)%(N)] == 1){
      change3 = (2+change2)%(N);
    }
    else{
      change3 = (change2+1)%(N);
    }
    */

    change3 = (int)(rand()%N);
    if(  (honey_server[(change3)%(N)] == 1 )){
      change3 = (++change3)%(N);
    }

    strcpy(old_pass3,passwords[change3]);


    /*    if(honey_server[(1+change3)%(N)] == 1){
      change4 = (2+change3)%(N);
    }
    else{
      change4 = (change3+1)%(N);
      }*/

    change4 = (int)(rand()%N);
    if( (honey_server[(change4)%(N)] == 1 )){
      change4 = (++change4)%(N);
    }

    strcpy(old_pass4,passwords[change4]);

    
    /*if(honey_server[(1+change4)%(N)] == 1){
      change5 = (2+change4)%(N);
    }
    else{
      change5 = (change4+1)%(N);
      }

    change5 = (int)(rand()%N);
    if( (honey_server[(change5)%(N)] == 1 )){
      change5 = (++change5)%(N);
    }


    strcpy(old_pass5,passwords[change5]);*/


    int len = rand()%5 + 8;
    for(j = 0; j < len; j++){
      passwords[change][j] = rand_char();
    }
    passwords[change][j] = '\0';

    len = rand()%5 + 8;
    for(j = 0; j < len; j++){
      passwords[change2][j] = rand_char();
    }
    passwords[change2][j] = '\0';


    len = rand()%5 + 8;
    for(j = 0; j < len; j++){
      passwords[change3][j] = rand_char();
    }
    passwords[change3][j] = '\0';


   len = rand()%5 + 8;
    for(j = 0; j < len; j++){
      passwords[change4][j] = rand_char();
    }
    passwords[change4][j] = '\0';


    /*    len = rand()%5 + 8;
    for(j = 0; j < len; j++){
      passwords[change5][j] = rand_char();
    }
    passwords[change5][j] = '\0';*/
    

    for(i=0;i<N;i++){
      //printf("%s\n",passwords[i]);
            j = 0;
      char c = passwords[i][j];
      while(c != '\0'){
	putchar_unlocked(c);
	j++;
	c = passwords[i][j];
      }
      putchar_unlocked('\n');

      fflush(stdout);
    }

    scanf("%d",&new_score);

    if(new_score < score){
      strcpy(passwords[change],old_pass);
      strcpy(passwords[change2],old_pass2);
      strcpy(passwords[change3],old_pass3);
      strcpy(passwords[change4],old_pass4);
      //      strcpy(passwords[change5],old_pass5);
    }
    else if(new_score == score){
      honey_server[change] = 1;
      honey_server[change2] = 1;
      honey_server[change3] = 1;
      honey_server[change4] = 1;
      //      honey_server[change5] = 1;
    }
    else{
      score = new_score;
    }
    server_no++;
    //    srand(rand()+time(NULL));
  }
  return 0;
}
