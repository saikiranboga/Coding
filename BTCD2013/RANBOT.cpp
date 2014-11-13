#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
  int n;
  map< int,vector <int> > pts;
  cin >> n;
  string s;
  int a,b,x,y;
  while(n--){
    cin >> s;
    cin >> a >> b;
    if(s[0] == 'a'){
      if(pts[a].size()){
	if( find(pts[a].begin(),pts[a].end(),b) == pts[a].end())
	  pts[a].push_back(b);
	sort(pts[a].begin(),pts[a].end());
      }
      else{
	pts[a].push_back(b);
      }
    }
    else if(s[0] == 'e'){
      pts[a].erase(remove(pts[a].begin(),pts[a].end(),b),pts[a].end());
      if(!pts[a].size())
	pts.erase(a);
    }
    else if(s[0] == 'g'){
      int flag = 0;
      map<int, vector<int> >::iterator x_pos;
      x_pos = pts.upper_bound(a);
      if(x_pos != pts.end() && pts[x_pos->first].size()){
	x = x_pos->first;
	for(int i=0;i<pts[x].size();i++){
	  if(pts[x][i]>b){
	    y = pts[x][i];
	    flag = 1;
	    break;
	  }
	}
      }
      if(flag)
	cout << x << " " << y << endl;
      if(!flag)
	cout << -1 << endl;
    }
  }  
  return 0;
}
