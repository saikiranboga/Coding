#include <stdio.h>
#include <string.h>

int main(){

  int t,len,len1,len2,i;
  char strng[10001];
  scanf("%d",&t);
  while(t--){
    scanf("%s",&strng);
    len = strlen(strng);
    int str1[26] = {0};
    int str2[26] = {0};
    if(len%2 != 0){
      printf("-1\n");
    }
    else{
      len1 = len/2;
      for(i=0;i<len1;i++){
	str1[strng[i]-'a']++;
      }
      for(i=len1;i<len;i++){
	str2[strng[i]-'a']++;
      }
      int ans = 0;
      for(i=0;i<26;i++){
	if(str1[i] > str2[i]){
	  ans += (str1[i]-str2[i]);
	}
      }
      printf("%d\n",ans);
    }
  }
  return 0;
}
