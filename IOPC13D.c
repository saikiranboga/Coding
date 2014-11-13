#include<stdio.h>

inline void fastRead(int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
}

int main(){
  int t;
  int n;
  fastRead(&t);
  while(t--){
    fastRead(&n);
    if(n%2 == 0){
      printf("YES\n");
    }else if(n%3 == 0){
      printf("YES\n");
    }
    else{
      printf("NO\n");
    }
  }
  return 0;
}
