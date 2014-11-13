#include<stdio.h>
#include<string.h>

int main(){
  int t,i,j,n;
  scanf("%d",&t);
  while(t--){
    char str[40002];
    int parent_alph[26] = {0};
    int children_alph[26] = {0};
    scanf("%s",&str);
    for( i=0; i < strlen(str); i++ ){
      parent_alph[str[i]-'a']++;
    }
    scanf("%s",&str);
    for( i=0; i < strlen(str); i++ ){
      parent_alph[str[i]-'a']++;
    }

    scanf("%d",&n);

    for(j=0;j<n;j++){
      scanf("%s",&str);
      for( i=0; i < strlen(str); i++ ){
	children_alph[str[i]-'a']++;
      } 
    }

    int flag = 1;
    for( i=0; i < 26; i++ ){
      if(parent_alph[i] < children_alph[i]){
	flag = 0;
	break;
      }
    }
    
    if(flag == 1){
      printf("YES\n");
    }
    else{
      printf("NO\n");
    }
  }
  return 0;
}
