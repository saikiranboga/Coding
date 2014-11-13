#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<long long int,int> a, pair<long long int,int> b){
	return a.first < b.first;
}

int main(){
	long long int n,k,p;
	//stores coordinate, index
	vector< pair<long long int, int> > xcoords,xcoords_orig;
	cin >> n >> k >> p;

	long long int coord;

	for(int i=0; i<n; i++){
		cin >> coord;
		xcoords.push_back(make_pair(coord,i));
		xcoords_orig.push_back(make_pair(coord,i));
	}
/*
	cout << "unsorted:\n";	
	for(int i=0; i<n; i++){
		cout << xcoords[i].first << " " << xcoords[i].second << endl;
	}
*/
	sort(xcoords.begin(), xcoords.end(), compare);
/*
	cout << "sorted:\n";
	for(int i=0; i<n; i++){
		cout << xcoords[i].first << " " << xcoords[i].second << endl;
	}
*/
	vector<long long int> disconts;

	for(int i=1; i<n; i++){
		if(xcoords[i].first-xcoords[i-1].first > k)
			disconts.push_back(xcoords[i].first);
	}
	
	int sz = disconts.size();

	long long int a, b;
	for(int i=0; i<p; i++){
		cin >> a >> b;
		// now find if there is a discontinuty position lies 
		// in these interval, if exists then they cannot communicate
		// else they can communicate
		vector<long long int>::iterator low, up;

		long long int aCoord = xcoords_orig[a-1].first;
		long long int bCoord = xcoords_orig[b-1].first;

		long long int l, r;

		if(aCoord<bCoord){
			l = aCoord;
			r = bCoord;
		} else{
			l = bCoord;
			r = aCoord;
		}

		up  = upper_bound(disconts.begin(), disconts.end(), l);
		int up_id = up-disconts.begin();

		if(up_id<sz && disconts[up_id]<=r)
			cout << "No\n";
		else
			cout << "Yes\n";
	}
	return 0;
}