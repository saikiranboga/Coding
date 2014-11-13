#include <iostream>

using namespace std;

int gcd(int a, int b){
  if(b == 0)
    return a;
  else
    return gcd(b,a%b);
}

int main(){
  int t,n,i;
  cin >> t;
  while(t--){
    cin >> n;
    int nums[n];

    for(i=0;i<n;i++)
      cin >> nums[i];

    int _gcd = nums[0];

    for(i=1;i<n;i++){
      if(_gcd > nums[i])
	_gcd = gcd(_gcd,nums[i]);
      else if(_gcd <nums[i])
	_gcd = gcd(nums[i],_gcd);
    }

    for(i=0;i<n;i++)
      cout << (nums[i]/_gcd) << " ";
    cout << endl;

  }
  return 0;
}
