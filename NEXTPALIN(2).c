#include <stdio.h>
#include<string.h>
char num[1000000];
char pal[1000000];
int len;
int flow;
 
void work(int pos1,int pos2){
    if(pos1 < 0){
        pal[len-1] = 49;
        flow = 1;
    }
    else if(pal[pos1] < '9'){
        pal[pos1] = pal[pos2] = ++pal[pos1];
    }else{
        pal[pos1] = pal[pos2] = 48;
        work(pos1-1,pos2+1);
        return;
    }
}
 
int main(){
  int i,t,flag,eq;
    scanf("%d",&t);
    while(t--){
        flag = 0;
        flow = 0;
	eq = 1;
        scanf("%s",&num);
        len = strlen(num);
        for(i=0;i<(len/2);i++)
            pal[i] = num[i];
        for(i=(len/2);i<len;i++)
            pal[i] = num[len-i-1];
        for(i=0;i<len;i++){
            if(pal[i] > num[i])
                flag = 1;
        }
	for(i=0;i<len;i++){
	  if(num[i] != num[len-1-i])
	    eq = 0;
	}
        if(flag != 1 && eq == 0){
            if(len%2 == 0){
                work((len/2)-1,len/2);
            }
            else{
                work(len/2,len/2);
            }
        }
        if(flow == 1){
            printf("1");
        }
        for(i=0;i<len;i++){
            printf("%c",pal[i]);
        }
        printf("\n");
    }
    return 0;
}
