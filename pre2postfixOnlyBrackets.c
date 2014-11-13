#include <stdio.h>
char stack[200];
int top=0;
void push(char c){
    stack[top++] = c;
}
char pop(){
    return stack[--top];
}
int main(void){
    char str[400];
    int i;
    int n,count;
    scanf("%d",&n);
    for(count = 1; count <=n; count++){
        i=0;
        scanf("%s",str);
        while(str[i] != '\0'){
            switch(str[i]){
                case '-':
                case '*':
                case '+':
                case '/':
                case '^':
                    push(str[i]);
                    break;
                case '(':
                    break;
                case ')':
                    printf("%c",pop());
                    break;
                default:
                    printf("%c",str[i]);
            }
            i++;
        }
        printf("\n");
    }
    return 0;
}
