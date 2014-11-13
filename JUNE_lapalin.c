#include<stdio.h>
#include<string.h>
int main(){

  int t,i;
  char ar[1001];
  int freq[26],freq2[26];
  scanf("%d",&t);
  while(t--){
    scanf("%s",&ar);

    for(i=0;i<26;i++){
      freq[i] = 0;
    }
    int len = strlen(ar);
    int half_len = len/2;
    for(i=0;i<26;i++){
      freq[i] = 0;
      freq2[i] = 0;
    }
    for(i=0;i<half_len;i++){
      freq[ar[i]-'a']++;
    }
    if(len%2 == 1){
      half_len += 1;
    }
    for(i=half_len;i<len;i++){
      freq2[ar[i]-'a']++;
    }
    int flag = 1;
    for(i=0;i<26;i++){
      if(freq[i] != freq2[i]){
	flag = 0;
	break;
      }
    }
    if(flag){
      printf("YES\n");
    }
    else{
      printf("NO\n");
    }
  }
  return 0;
}
