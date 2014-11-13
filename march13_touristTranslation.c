#include<stdio.h>
#include<string.h> 
int main(){
  int t,i; 
  char chr; 
  char ar[26]; 
  char sent[100];
  scanf("%d%s",&t,&ar);   
  while(t--){  
    scanf("%s",&sent);
    for(i=0;i<strlen(sent);i++){
      chr = sent[i];
      if(chr >=97 && chr <= 122){   
	printf("%c",ar[(int)(chr-'a')]);
      }  
      else if(chr >=65 && chr <= 90){   
	printf("%c",(char)(ar[(int)(chr-'a'+32)]-32));     
      } 
      else if(chr == '_'){   
	printf(" ");   
      }    
      else{ 
        printf("%c",chr);   
      }    
    }  
    printf("\n"); 
  }  
  return 0;
}
