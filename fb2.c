#include<stdio.h>
#include<string.h>
int balpar(char a[], int first, int last){
  int flag=0;
  char p,q;
  p = a[first];
  q = a[last];
  if(first == last || first>last)
    return 1;
  while((p>96 && p<123) || (p == 32)){
    first++;
    p = a[first];
  }
  while((q>96 && q<123) || (q == 32)){
    last--;
    q = a[last];
  }
  if(p == '(')
    flag = 1;
  if(q == '('){
    if(a[last-1] == ':')
      last -= 2;
    else
      return 0;
  }
  else if(q == ')'){
    if(flag == 1){
      flag = 0;
      last -= 1;
      first +=1;
    }
    else if(a[last-1] == ':'){
      last -= 2;
    }
    else
      return 0;
  }
  if(balpar(a,first,last)==1)
    return 1;
  else
    return 0;
}

int main(){
  int m,t;
  char ar[100];
  char c[10];
  scanf("%d",&t);
  gets(c);
  for(m=1;m<=t;m++){
    gets(ar);
    if(balpar(ar,0,strlen(ar)-1) == 1)
      printf("case #%d: YES\n",m);
    else
      printf("case #%d: NO\n",m);
  }
  return 0;
}
