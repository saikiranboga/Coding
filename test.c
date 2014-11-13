#include <stdio.h>

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
  int a = 1;
  fastRead(&a);
  while(a != 42){
      printf("%d\n",a);
      fastRead(&a);
  }
  return 0;
} 
