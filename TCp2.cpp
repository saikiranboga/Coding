#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
string NumberToString(T pNumber){
  ostringstream oOStrStream;
  oOStrStream << pNumber;
  return oOStrStream.str();
}

class BinaryCode{
public:
  vector<string> decode(string encrStr){
    int i;
    int length = encrStr.length();
    vector<string> ans;
    int Q[length];
    for(i=0; i<length; i++){
      Q[i] = (int)encrStr[i]-(int)'0';
    }
    if(encrStr[0] == '3' || encrStr[length-1] == '3'){
      ans.push_back("NONE");
      ans.push_back("NONE");
      return ans;
    }
    else if(encrStr[0] == '2'){
      ans.push_back("NONE");
      int P[length];
      P[0] = P[1] = 1;
      string tmp = "11";
      for(i=2; i<length; i++){
	P[i] = Q[i-1]-P[i-1]-P[i-2];
	if(P[i] > 1){
	  ans.push_back("NONE");
	  return ans;
	}
	else{
	  tmp += NumberToString(P[i]);
	}
      }
      if(Q[length-1] == P[length-1]+P[length-2])
	ans.push_back(tmp);
      else
	ans.push_back("NONE");
      return ans;
    }
    else if(encrStr[0] == '0'){
      int P[length];
      P[0] = P[1] = 0;
      string tmp;
      if(length>1)
      	tmp = "00";
      else
      	tmp = "0";
      for(i=2; i<length; i++){
	P[i] = Q[i-1]-P[i-1]-P[i-2];
	if(P[i] > 1){
	  ans.push_back("NONE");
	  ans.push_back("NONE");
	  return ans;
	}
	else{
	  tmp += NumberToString(P[i]);
	}
      }
      if(Q[length-1] == P[length-1]+P[length-2])
	ans.push_back(tmp);
      else
	ans.push_back("NONE");
      ans.push_back("NONE");
      return ans;
    }
    else{
      int P[length],flag=0;
      P[0] = 0; P[1] = 1;
      string tmp;
      if(length>1)
      	tmp = "01";
      else
      	tmp = "0";
      for(i=2; i<length; i++){
	P[i] = Q[i-1]-P[i-1]-P[i-2];
	if(P[i] > 1){
	  ans.push_back("NONE");
	  flag = 1;
	  break;
	}
	else{
	  tmp += NumberToString(P[i]);
	}
      }
      if(flag == 0)
	if(Q[length-1] == P[length-1]+P[length-2])
	  ans.push_back(tmp);
	else
	  ans.push_back("NONE");

      flag = 0;
      P[0] = 1; P[1] = 0;
      if(length>1)
	  	tmp = "10";
	  else
	  	tmp = "1";
      for(i=2; i<length; i++){
	P[i] = Q[i-1]-P[i-1]-P[i-2];
	if(P[i] > 1){
	  ans.push_back("NONE");
	  flag = 1;
	  return ans;
	}
	else{
	  tmp += NumberToString(P[i]);
	}
      }
      if(flag == 0)
	if(Q[length-1] == P[length-1]+P[length-2])
	  ans.push_back(tmp);
	else
	  ans.push_back("NONE");
      return ans;
    }
  }
};


int main(){
  BinaryCode bc;
  vector<string> ans;
  ans = bc.decode("111323012211013231000233331110223030100330");
  cout << ans.size();
  string a;
  a = "{ \"" + ans[0] + "\",  " + "\"" + ans[1] + '"' + " }";
  cout << a << endl;
  return 0;
}

