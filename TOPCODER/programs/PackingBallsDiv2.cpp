#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class PackingBallsDiv2 {
public:
	int minPacks(int, int, int);
};

int PackingBallsDiv2::minPacks(int R, int G, int B) {
	int ans2 = ((R-1)/3) + ((G-1)/3) + ((B-1)/3) + 3;
	int mn = min( R, min(G,B) );
	int ans = 0;
	ans += mn;
	R -= mn;
	G -= mn;
	B -= mn;
	if(R==0){
		if(G!=0 && B!=0){
			mn = min(G, B);
			ans += mn;
			G -= mn;	B -= mn;
			if(G==0){
				if(B!=0)
					ans += ( ((B-1)/3)+1 );
			}
			else{
				ans += ( ((G-1)/3)+1 );
			}
		}
		else{
			if(G==0){
				if(B!=0)
					ans += ( ((B-1)/3)+1 );
			}
			else{
				ans += ( ((G-1)/3)+1 );
			}
		}
	}
	else if(G==0){
		if(R!=0 && B!=0){
			mn = min(R, B);
			ans += mn;
			R -= mn;	B -= mn;
			if(R==0){
				if(B!=0)
					ans += ( ((B-1)/3)+1 );
			}
			else{
				ans += ( ((R-1)/3)+1 );
			}
		}
		else{
			if(R==0){
				if(B!=0)
					ans += ( ((B-1)/3)+1 );
			}
			else{
				ans += ( ((R-1)/3)+1 );
			}
		}
	}
	else if(B==0){
		if(G!=0 && R!=0){
			mn = min(G, R);
			ans += mn;
			G -= mn;	R -= mn;
			if(G==0){
				if(R!=0)
					ans += ( ((R-1)/3)+1 );
			}
			else{
				ans += ( ((G-1)/3)+1 );
			}
		}
		else{
			if(G==0){
				if(R!=0)
					ans += ( ((R-1)/3)+1 );
			}
			else{
				ans += ( ((G-1)/3)+1 );
			}
		}
	}
	return min(ans, ans2);
}


double test0() {
	int p0 = 4;
	int p1 = 2;
	int p2 = 4;
	PackingBallsDiv2 * obj = new PackingBallsDiv2();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 1;
	int p1 = 7;
	int p2 = 1;
	PackingBallsDiv2 * obj = new PackingBallsDiv2();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 2;
	int p1 = 3;
	int p2 = 5;
	PackingBallsDiv2 * obj = new PackingBallsDiv2();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 78;
	int p1 = 53;
	int p2 = 64;
	PackingBallsDiv2 * obj = new PackingBallsDiv2();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 66;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 100;
	int p1 = 100;
	int p2 = 100;
	PackingBallsDiv2 * obj = new PackingBallsDiv2();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 100;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
