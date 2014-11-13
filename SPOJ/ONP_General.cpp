#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

#define ll long long

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define ford(i, up, bot) for(int i = (up); i > (bot); --i)
#define fordi(i, up, bot) ford(i, up, bot-1)

#define pb push_back
#define mp make_pair

typedef pair<int, int> pt;

// string infix stores the current algebraic expression
// that is to be converted
string infix;

// we are given that the maximum length of the algebraic
// expression is 400;
// then the operators stack size must be at max half of 
// the length of the expression.
#define MAX_LEN 400
#define MAX_STK_SIZE MAX_LEN/2

// op_stack is used to store the operators, in order;
// bracket is used to store the starting position
// of the first operator after the start of bracket;
char op_stack[MAX_STK_SIZE];
int bracket[MAX_STK_SIZE];

// stk_prio stores the priority of the top
// element of the op_stack;

// brkt_ind stores the index on the bracket array
// to insert the starting index of the first stack symbol
// after the starting bracket on the op_stack;

// stk_ind stores the index on the op_stack, to
// insert an element;

int stk_prio, brkt_ind, stk_ind;

//returns the priority of a op_stack symbol
int getPrio(int ind){
	if(ind<0)
		return 0;
	char c = infix[ind];
	if(c=='+' || c=='-')
		return 1;
	if(c=='*' || c=='/')
		return 2;
	if(c=='^')
		return 3;
	return 0;
}

// process the stack if its priority is more
// than the current symbol priority
void process(char cur, int prio){
	while(stk_prio>prio && brkt_ind<stk_ind){
		cout << op_stack[--stk_ind];
		stk_prio = getPrio(stk_ind-1);
	}
	op_stack[stk_ind++] = cur;
	stk_prio = prio;
}

void convert(int ind){
	//process end of expression
	if(ind >= infix.size()){
		while(--stk_ind>=0){
			cout << op_stack[stk_ind];
		}
		cout << endl;
		return;
	}

	char c = infix[ind];
	int prio = getPrio(ind);
	//cout << endl << ind << " " << c << " " << prio << endl;
	switch(c){
		case '+':
		case '-':
		{
			if(stk_prio<=prio){
				op_stack[stk_ind++] = c;
				stk_prio = prio;
			}
			else{
				process(c, prio);
			}
			break;
		}
		case '*':
		case '/':
		{
			if(stk_prio<=prio){
				op_stack[stk_ind++] = c;
				stk_prio = prio;
			}
			else{
				process(c, prio);
			}
			break;
		}
		case '^':
		{
			if(stk_prio<=prio){
				op_stack[stk_ind++] = c;
				stk_prio = prio;
			}
			else{
				process(c, prio);
			}
			break;
		}
		case '(':
		{
			bracket[brkt_ind++] = stk_ind;
			break;
		}
		case ')':
		{
			brkt_ind--;
			for(int i=--stk_ind; i>=bracket[brkt_ind];i--){
				cout << op_stack[i];
				stk_prio = getPrio(i-1);
			}
			break;
		}		
		default:
		{
			cout << c;
		}
	}
	int in = ind+1;
	convert(in);
	return;
}

int main(){	
	int t;
	cin >> t;
	while(t--){
		cin >> infix;
		stk_prio = 0;
		brkt_ind = 0;
		stk_ind = 0;
		convert(0);
	}
	return 0;
}