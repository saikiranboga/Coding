#include<stdio.h>
#include<string.h>
int main(){
  FILE* fp = fopen("googleCodeJam13_Qual1_output.txt","w+");
  char ar[5][5];
  int t,k,i,j;
  char c;
  scanf("%d",&t);
  for(k=1;k<=t;k++){
    for(i=0;i<4;i++){
      scanf("%s",&ar[i]);
    }
    char win = 'N';
    for(i=0;i<4;i++){
      if(strcmp(ar[i],"XXXX") == 0 || strcmp(ar[i],"TXXX") == 0 || strcmp(ar[i],"XTXX") == 0 || strcmp(ar[i],"XXTX") == 0 || strcmp(ar[i],"XXXT") == 0){
	win = 'X';
      }
      else if(strcmp(ar[i],"OOOO") == 0 || strcmp(ar[i],"TOOO") == 0 || strcmp(ar[i],"OTOO") == 0 || strcmp(ar[i],"OOTO") == 0 || strcmp(ar[i],"OOOT") == 0){
	win = 'O';
      }
    }
    char str[5];
    if(win == 'N'){
      for(i=0;i<4;i++){
	for(j=0;j<4;j++){
	  str[j] = ar[j][i];
	}
	if(strcmp(str,"XXXX") == 0 || strcmp(str,"TXXX") == 0 || strcmp(str,"XTXX") == 0 || strcmp(str,"XXTX") == 0 || strcmp(str,"XXXT") == 0){
	  win = 'X';
	}
	else if(strcmp(str,"OOOO") == 0 || strcmp(str,"TOOO") == 0 || strcmp(str,"OTOO") == 0 || strcmp(str,"OOTO") == 0 || strcmp(str,"OOOT") == 0){
	  win = 'O';
	}
      }
    }
    if(win == 'N'){
      for(i=0;i<4;i++){
	str[i] = ar[i][i];
      }
      if(strcmp(str,"XXXX") == 0 || strcmp(str,"TXXX") == 0 || strcmp(str,"XTXX") == 0 || strcmp(str,"XXTX") == 0 || strcmp(str,"XXXT") == 0){
	win = 'X';
      }
      else if(strcmp(str,"OOOO") == 0 || strcmp(str,"TOOO") == 0 || strcmp(str,"OTOO") == 0 || strcmp(str,"OOTO") == 0 || strcmp(str,"OOOT") == 0){
	win = 'O';
      }
    }

    if(win == 'N'){
      for(i=0,j=3;i<4,j>=0;i++,j--){
	  str[i] = ar[i][j];
      }
      if(strcmp(str,"XXXX") == 0 || strcmp(str,"TXXX") == 0 || strcmp(str,"XTXX") == 0 || strcmp(str,"XXTX") == 0 || strcmp(str,"XXXT") == 0){
	win = 'X';
      }
      else if(strcmp(str,"OOOO") == 0 || strcmp(str,"TOOO") == 0 || strcmp(str,"OTOO") == 0 || strcmp(str,"OOTO") == 0 || strcmp(str,"OOOT") == 0){
	win = 'O';
      }
    }

    int progress = 0;
    if(win == 'N'){
      for(i=0;i<4;i++){
	for(j=0;j<4;j++){
	  if(ar[j][i] == '.'){
	    progress = 1;
	    break;
	  }
	}
      }
    }

    if(win != 'N'){
      fprintf(fp,"Case #%d: %c won\n",k,win);
    }
    else if(progress == 1){
      fprintf(fp,"Case #%d: Game has not completed\n",k);
    }
    else
      fprintf(fp,"Case #%d: Draw\n",k);
  }
  fclose(fp);
  return 0;
}
