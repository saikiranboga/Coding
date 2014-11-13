#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  int top_value = 220000;
  int *array    = calloc( top_value + 1, sizeof(int));
  int i, prime, multiple;

  int ans[top_value+1];

  array[1] = 0;

  for(i=2; i <= top_value; ++i) 
    array[i] = 1;

  for(prime = 2; prime <= top_value; ++prime){
    if(array[prime])
      for(multiple = 2*prime; multiple <= top_value; multiple += prime)
	if(array[multiple]) {
	  array[multiple] = 0;
	}
  }
  int count = 0;
  for(i=1; i <= top_value; ++i){
    if (array[i]){
      count++;
    }
    ans[i] = count;
  }

  int n,t;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    printf("%d\n",ans[n]);
  }
  return 0;
}
