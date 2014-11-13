#include<iostream>
#include<hash_map>
using namespace std;

int main(){
  hash_map<int,int> hash;
  hash[2] = 5;
  cout << hash[2] << endl;
  return 0;
}
