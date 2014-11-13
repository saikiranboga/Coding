#include<stdio.h>
int main(){
  int n,s,t,d;
  scanf("%d",&n);
  while(n--){
    scanf("%d%d%d",&s,&t,&d);
    if(s+t<=d)
      printf("%d\n",d-(s+t));
    else if(s>=t){
	if(s-t>d)
	  printf("%d\n",s-(t+d));
	else
	  printf("0\n");
      }
    else if(s<t){
	if(t-s>d)
	  printf("%d\n",t-(s+d));
	else
	  printf("0\n");
    }
    else
      printf("0\n");
  }
  return 0;
}
