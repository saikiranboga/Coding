#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(){
int n= 8;
	printf("%d\n",n&(n-1) );
  return 0;
}
