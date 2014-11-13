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

class FixedDiceGameDiv2 {
public:
	double getExpectation(int, int);
};

double FixedDiceGameDiv2::getExpectation(int a, int b) {
	double aa = (double)a;
	double ev = 0.00;
	double sigA = ((double)(aa*(aa+1)))/2.0;
	double ans = 0.0;
	double nTimes = 0.0;
	for(int i=1;i<=b;i++){
		if(i<a){
			nTimes += (double)(aa-i);
			double sigI = ((double)(i*(i+1)))/2.0;
			ans += (double)(sigA-sigI);
		}
	}
	if(nTimes!=0)
		ev = ans/(double)nTimes;
	else
		ev = 0.0;
	return ev;
}


//Powered by [KawigiEdit] 2.0!
