#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define LL long long int

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

int marked[1000010], nums[1000010];
int prev[1000010], nxt[1000010];

int main(){
    int n;
    cin >> n;
    int a, b;
    memset(marked, 0, sizeof(marked) );
    memset(prev, -1, sizeof(prev) );
    memset(nxt, -1, sizeof(nxt) );
    memset(nums, 0, sizeof(nums) );
    for (int i = 0; i < n; ++i){
        cin >> a >> b;
        prev[b] = a;
        nxt[a] = b;
        nums[a] = 1, nums[b] = 1;
    }

    vector<int> first, left, right, second;
    int st = 0;
    while(nxt[st]!=-1 && nxt[st]!=0){
    	first.pb(nxt[st]);
    	st = nxt[st];
    	marked[st] = 1;
    }

    for(int i = 1; i < 1000010; ++i){
    	if(nums[i] && marked[i]==0){
    		st = i;
    		break;
    	}
    }

    int pivot = st;
    right.pb(st);
    while(nxt[st]!=-1 && nxt[st]!=0){
    	st = nxt[st];
    	right.pb(st);
    }

    while(prev[pivot]!=0 && prev[pivot]!=-1){
    	left.pb(prev[pivot]);
    	pivot = prev[pivot];
    }

    for(int i = left.sz-1; i>=0; --i)
    	second.pb(left[i]);
    for(int i = 0; i < right.sz; ++i)
    	second.pb(right[i]);

    int c1=0, c2=0;
    for(int i = 0; i < n; ++i){
    	if(i%2==0){
    		cout << second[c1] << " ";
    		c1++;
    	}
    	else{
    		cout << first[c2] << " ";
    		c2++;
    	}
    }
    cout << endl;
    return 0;
}

/*
5
0 94
88 3
94 6
3 8
6 0
*/