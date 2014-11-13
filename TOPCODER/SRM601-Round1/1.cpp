#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class WinterAndMandarins{
public:
  int getNumber(vector <int> bags, int k){
    int N = bags.size();
    sort(bags.begin(),bags.end());
    int min = 1000000000;
    int dif;
    int up = bags.size()-k;
    for(int i=0;i<=up;i++){
      dif = bags[i+k-1]-bags[i];
      if(dif < min)
	min = dif;
    }
    return min;
  }
};

int main(){
  WinterAndMandarins *wm = new WinterAndMandarins();
  int t,n,k;
  while(t--){
    vector <int> a;
    cin >> n >> k;
    int x;
    for(int i=0;i<n;i++){
      cin >> x;
      a.push_back(x);
    }
    cout << wm->getNumber(a, k) << endl;
  }
  return 0;
}
