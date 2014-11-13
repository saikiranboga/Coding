#include<stdio.h>
#include<string.h>
int main(){
  int i,len=0;
  char s[2013];
  char *p;
  int indx[2013];
  scanf("%s",&s);
  len=strlen(s);
  p=strstr(s,"CHE?");
  printf("%s",p);
  return 0;
}
