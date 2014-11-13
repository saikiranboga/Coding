#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

template <typename T>
string NumberToString(T pNumber)
{
 ostringstream oOStrStream;
 oOStrStream << pNumber;
 return oOStrStream.str();
}

class Time{
 public:
  string whatTime(int seconds){
    int hrs = seconds/3600;
    int temp = seconds-hrs*3600;
    int mts = (temp)/60;
    int secs = temp-mts*60;
    string ans = NumberToString(hrs)+ ":" +NumberToString(mts) +  ":" +NumberToString(secs);
    return ans;
  }
};

int main(){
  Time t;
  cout << t.whatTime(0) << endl;
}
