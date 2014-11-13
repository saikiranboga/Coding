#include<stdio.h>

#define MAX_LEN 400
#define STK_SIZE 200

char infix[MAX_LEN];
char stack[STK_SIZE];
int brkt[STK_SIZE];
int stk_prio;
int stk_indx;
int brkt_indx;


int givePrio(int indx){
  if(indx < 0)
    return 0;
  else{
    switch(stack[indx]){
    case '+':
    case '-':
      {
	return 1;
	break;
      }
    case '*':
    case '/':
      {
	return 2;
	break;
      }
    case '^':
      {
	return 3;
      }
    }
  }
}

void convert(int ind){
  int i,index = ind;
  char c = infix[index++];
  switch(c){
  case '+':
  case '-':
    {
      if(stk_prio <= 1){
	stack[stk_indx++] = c;
	stk_prio = 1;
      }
      else{
	while(stk_prio>1 && brkt_indx<stk_indx){
	  printf("%c",stack[--stk_indx]);
	  stk_prio = givePrio(stk_indx-1);
	}
	stack[stk_indx++] = c;
	stk_prio = 1;
      }
      convert(index);
      break;
    }
  case '*':
  case '/':
    {
      if(stk_prio <= 2){
	stack[stk_indx++] = c;
	stk_prio = 2;
      }
      else{
	while(stk_prio>2 && brkt_indx<stk_indx){
	  printf("%c",stack[--stk_indx]);
	  stk_prio = givePrio(stk_indx-1);
	}
	stack[stk_indx++] = c;
	stk_prio = 2;
      }
      convert(index);
      break;
    } 
 case '^':
    {
      if(stk_prio <= 3){
	stack[stk_indx++] = c;
	stk_prio = 3;
      }
      else{
	while(stk_prio > 3){
	  printf("%c",stack[--stk_indx]);
	  stk_prio = givePrio(stk_indx-1);
	}
	stack[stk_indx++] = c;
	stk_prio = 3;
      }
      convert(index);
      break;
    }
  case '(' :
    {
      brkt[brkt_indx++] = stk_indx;
      convert(index);
      break;
    }
  case ')':
    {
      brkt_indx--;
      for(i=(--stk_indx);i >= brkt[brkt_indx];i--){
	printf("%c",stack[i]);
	stk_prio = givePrio(i-1);
      }
      convert(index);
      break;
    }
  case '\0':
    {
      while(--stk_indx >=0){
	printf("%c",stack[stk_indx]);
      }
      break;
    }
  default:
    {
      printf("%c",c);
      convert(index);
    }
  }
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    scanf("%s",&infix);
    stk_indx = 0;
    brkt_indx = 0;
    stk_prio = 0;
    convert(0);
    printf("\n");
  }
  return 0;
}
