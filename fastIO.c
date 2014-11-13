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

int main(void){
  int n,k,i,count;
  count = 0;
  fastRead(&n);
  fastRead(&k);
  int array[n];
  for(i=0; i<n; i++){
    fastRead(&array[i]);
  }
  for(i=0; i<n; i++){
    if((array[i]%k) == 0)
      count++;
  }
  printf("%d",count);
  return 0;
}
