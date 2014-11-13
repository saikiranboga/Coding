#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char* lcs(const char *a, const char *b, char *out)
{
  int longest = 0;
  int match(const char *a, const char *b, int dep) {
    if (!a || !b) return 0;
    if (!*a || !*b) {
      if (dep <= longest) return 0;
      out[ longest = dep ] = 0;
      return 1;
    }
 
    if (*a == *b)
      return match(a+1, b+1, dep+1) && (out[dep] = *a);
 
    return	match(a+1, b+1, dep) +  match(strchr(a, *b), b, dep) + match(a, strchr(b, *a), dep);
  }
 
  return match(a, b, 0) ? out : 0;
}
 
int main()
{
  char str1[30000],str2[30000],buf[30000];
  int t;
  scanf("%d",&t);

  while(t--){
    scanf("%s%s",&str1,&str2);
    int seqlen = strlen(lcs(str1,str2,buf));
    if( (seqlen == strlen(str1)) || (seqlen == strlen(str2)))
      printf("YES\n");
    else 
      printf("NO\n");
  }
  return 0;
}
