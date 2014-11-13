#include <iostream>
#include <vector>
using namespace std;

class Stack{
public:
	int size;
	static const int Mx = 100000;
	int mem[Mx];
	Stack(){
		size = 0;
	}
	int top(){
		return mem[size-1];
	}
	void push(int x){
		if(size == Mx)
			cout << "Stack Full!" << endl;
		else{
			size = size+1;
			mem[size-1] = x;
		}
	}
	int pop(){
		if(size == 0)
			cout << "Stack Empty!\n";
		else{
			int ret = mem[size-1];
			size = size-1;
			return ret;
		}
	}
	void print(){
		cout << "stack: \n";
		for (int i = 0; i < size; ++i)
			cout << mem[i] << " ";
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	Stack* s = new Stack();
	int op, x;
	while(1){
		cin >> op;
		switch(op){
			case 1:
				cin >> x;
				s->push(x);
				s->print();
				break;
			case 2:
				s->pop();			
				s->print();
				break;
			case 3:
				cout << "top:" << s->top() << endl;
				break;
			case 4:
				return 0;
				break;
			default:
				return 0;
		}
	}
	return 0;
}