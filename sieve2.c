#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  int top_value,m;
  scanf("%d",&m);
  scanf("%d",&n);
  int     count     = n - 1;
  int     *array    = calloc( top_value + 1, sizeof(int));
  int     i, prime, multiple;
  /* mark each int as prime  */
  for (i=2; i <= top_value; ++i) 
    array[i] = 1;
  /* for each starting prime, mark its every multiple as non-prime         */
  for (prime = 2; prime <= top_value; ++prime)
    {
      if (array[prime])
	for (multiple = 2*prime; multiple <= top_value; multiple += prime)
	  if (array[multiple]) {
	    array[multiple] = 0;
	    --count;
	  }
    }
  /* Now that we have marked all multiples of primes as non-prime, print   */
  /* the remaining numbers that fell through the sieve, and are thus prime */
  for (i=m; i <= top_value; ++i)
    {
      if (array[i])
	printf("%d\n", i);
    }
  printf("\n\n %d primes up to %d found.\n", count, top_value);
  exit(0);
}
