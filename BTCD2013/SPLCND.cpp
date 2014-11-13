#include <stdio.h>
//#include <iostream>
//using namespace std;

inline void fastRead(int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
}

int main(){
  int t,i,min,n;
  //  cin >> t;
  fastRead(&t);
  while(t--){
    min = 100000000;
    //    cin >> n;
    fastRead(&n);
    int xr,tmp;
    long long int sum = 0;
    //    cin >> xr;
    fastRead(&xr);
    if(xr < min)
      min = xr;
    sum += xr;
    for(i=1;i<n;i++){
      //      cin >> tmp;
      fastRead(&tmp);
      sum += tmp;
      if(tmp < min)
	min = tmp;
      xr ^= tmp;
    }

    if(!xr){
      //      cout << (sum-min) << endl;
      printf("%lld\n",(sum-min));
    }
    else
      //      cout << "NO\n";
      printf("NO\n");
  }
  return 0;
}
