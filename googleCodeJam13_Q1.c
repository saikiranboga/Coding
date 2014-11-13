#include<stdio.h>
#include<stdlib.h>

int main(){
  char mapping[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
  int i,j,t,length;
  char c;
  char str[100];
  scanf("%d%c",&t,&c);
  FILE *fp = fopen("output.txt","w+");
  for(i=1;i<=t;i++){
    c = 'a';
    j = 0;
    length=0;
    while(c != '\n'){
      length++;
      scanf("%c",&c);

      if(c != ' ' && c != '\n'){
	str[j++] = mapping[c-'a'];
      }
      else if(c == ' '){
	str[j++] = ' ';
      }
    }
    fprintf(fp,"Case #%d: ",i);
    for(j = 0;j<length-1;j++){
      fprintf(fp,"%c",str[j]);
    }
    fprintf(fp,"\n");
  }
  fclose(fp);
  return 0;
}
