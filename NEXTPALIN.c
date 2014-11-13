#include<stdio.h>
char num[1000000];
void palin(int start, int end){
    int i,d,current = end,carry;
    int str = num[start], ed = num[end];
    if(str == ed){
    }
    else if(str > ed){
        num[end] = num[start];
    }
    else{
        d = num[start];
        num[current--] = d;
        carry = 1;
        while(carry > 0 && current >= 0){
            d = (int)(num[current]-48);
            d += carry;
            num[current--] = (d%10)+48;
            carry = d/10;
        }
        if(current == start-1){
            num[end]++;
        }
    }
    if(start+1<end-1)
        palin(start+1,end-1);
}
int main(){
    int t,i,d,len,carry,current;
    scanf("%d",&t);
    while(t--){
        len = 0;
        scanf("%s",&num);
        for(i=0;num[i] != '\0';i++)
            len++;
        palin(0,len-1);
        for(i=0;i<len;i++)
            printf("%c",num[i]);
        printf("\n");
    }
    return 0;
}
