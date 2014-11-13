#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class WinterAndCandies{
public:
  int getNumber(vector <int> type){

    int N = type.size();
    int freq[51];
    for(int i=0;i<=50;i++)
      freq[i] = 0;
    
    for(int i=0;i<N;i++)
      freq[ type[i] ]++;

    int ans = freq[1];
    int i = 2;
    while(i<=50 && freq[i] != 0){
      freq[i] *= freq[i-1];
      ans += freq[i];
      i++;
    }
    return ans;
  }
};

int main(){
  int n;
  while(true){
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
      cin >> a[i];
    vector<int> vc(a,a+n);
    WinterAndCandies* wc = new WinterAndCandies();
    cout << wc->getNumber(vc) << endl;
  }
  return 0;
}
