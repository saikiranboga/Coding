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

class PathGameDiv2 {
public:
	int n;
	int calc(vector <string>);
};

int PathGameDiv2::calc(vector <string> board) {
	n = board[0].size();
	int black_cnt = 0;
	int tot = 2*n;
	int dist[tot][tot];
	int inf = 1000000;
	
	for(int i=0; i<tot; i++)
		for(int j=0; j<tot; j++)
			dist[i][j] = inf;

	for(int i=0; i<tot; i++)
		dist[i][i] = 0;

	for(int i=0; i<2; i++){
		for(int j=0; j<n-1; j++){
			if(board[i][j]=='.'){
				if(board[i][j+1]=='.')
					dist[i*n+j][i*n+j+1] = 1;
				if(board[1-i][j]=='.')
					dist[i*n+j][(1-i)*n+j] = 1;
			}
			else{
				black_cnt++;
			}
		}
	}
	if(board[0][n-1]=='#')
		black_cnt++;
	if(board[1][n-1]=='#')
		black_cnt++;

	for(int k=0; k<tot; k++){
		for(int i=0; i<tot; i++){
			for(int j=0; j<tot; j++){
				if(dist[i][j]>dist[i][k]+dist[k][j])
					dist[i][j] = dist[i][k]+dist[k][j];
			}
		}
	}


	// for(int i=0; i<tot; i++){
	// 	for(int j=0; j<tot; j++)
	// 		cout << dist[i][j] << " ";
	// 	cout << endl;
	// }

	int minm = min( dist[0][n-1], dist[0][tot-1] );
	minm = min( minm, dist[n][n-1] );
	minm = min( minm, dist[n][tot-1] );
	// cout << "minm " << minm << endl;
	int ans = tot - minm - 1 - black_cnt;
	return ans;
}

double test0() {
	string t0[] = {"#...."
				  ,"...#."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PathGameDiv2 * obj = new PathGameDiv2();
	clock_t start = clock();
	int my_answer = obj->calc(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"#"
,"."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PathGameDiv2 * obj = new PathGameDiv2();
	clock_t start = clock();
	int my_answer = obj->calc(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"."
,"."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PathGameDiv2 * obj = new PathGameDiv2();
	clock_t start = clock();
	int my_answer = obj->calc(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"....#.##.....#..........."
,"..#......#.......#..#...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PathGameDiv2 * obj = new PathGameDiv2();
	clock_t start = clock();
	int my_answer = obj->calc(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 13;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
