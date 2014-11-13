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

class TypoCoderDiv2 {
public:
	int count(vector <int>);
};

int TypoCoderDiv2::count(vector <int> rating) {
	int N = rating.size();
	int ans = 0;
	for(int i=1;i<N;i++){
	  if( (rating[i] >= 1200 && rating[i-1] < 1200) || (rating[i] < 1200 && rating[i-1]>=1200))
	    ans++;
	}
	return ans;
}

int main() {
  TypoCoderDiv2 *t = new TypoCoderDiv2();
  int a[] = {1000,1200,1199};
  vector<int> aa(a,a+3);
  cout << t->count(aa) << endl;
  return 0;
}

//Powered by [KawigiEdit] 2.0!
