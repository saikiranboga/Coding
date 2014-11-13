#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

#define ll long long

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define ford(i, up, bot) for(int i = (up); i > (bot); --i)
#define fordi(i, up, bot) ford(i, up, bot-1)

#define pb push_back
#define mp make_pair

typedef pair<int, int> pt;

bool comp(int a, int b){
	return a > b;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int nums[n];
	forn(i, n)
		cin >> nums[i];
	sort(nums, nums+n, comp);
	int idx;
	while(nums[0] > nums[n-1]){
		forn(i, n-1){
			if(nums[i]>nums[i+1])
				nums[i] = nums[i] - nums[i+1];
		}
		sort(nums, nums+n, comp);
	}
	int ans = 0;
	forn(i, n)
		ans += nums[i];
	cout << ans << endl;
	return 0;
}