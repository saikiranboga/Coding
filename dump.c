#include<stdio.h>

int main(){
 int i = 2;
 char c;
 i = scanf("%c %c %c %c",&c,&c,&c, &c); // scans left to right
 printf("%d %c\n",i,c);
 //printf("%d %d\n",scanf("%d",&i),scanf("%d",&i));
 int j = ++i;
 printf("%d\n",i++);
 printf("%d %d %d %d %d\n",j,++j,j++,++j,j++); // evaluates right to left
 
 int a = 10;
 int *p = &a;
 printf("%d, %d\n",p,*p);
 *p++;
 printf("%d, %d\n",p,*p);
}
