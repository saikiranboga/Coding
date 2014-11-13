//http://discuss.codechef.com/questions/7697/tastr-editorial
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 100000
#define MAX_STEPS 65

typedef struct tuple
{
	int sort_index_cur_len;
	int sort_index_next_len;
	int index;
}tuple;

tuple L[MAXN];

int pos[MAXN][MAX_STEPS];
int N;
int step;
int doneTill;

int compare(tuple a,tuple b){
	return a.sort_index_cur_len==b.sort_index_cur_len ? (a.sort_index_next_len<b.sort_index_next_len?1:0) : (a.sort_index_cur_len<b.sort_index_cur_len?1:0);
}


// LCP start

int lcp(int x, int y){
	int ret = 0;
	if(x == y)
		return N-x;
	for( int k=step-1; k>=0 && x<N && y<N; k--){
		if( pos[k][x] == pos[k][y] ){
			x += 1<<k;
			y += 1<<k;
			ret += 1<<k;
		}
	}
	return ret;
}

// end


int main(){

	string s;
	cin >> s;
	N = s.length();
	// initial positions of strings compared with length 1
	for(int i=0;i<N;i++)
		pos[0][i] = s[i]-'a';

	doneTill = 1;
	step = 1;

	// sort strings for lengths of multiples of 2
	while(doneTill < N){

		for(int i=0;i<N;i++){
			L[i].sort_index_cur_len = pos[step-1][i];
			L[i].sort_index_next_len = (i+doneTill)<N? pos[step-1][i+doneTill] : -1;
			L[i].index = i;
		}

		sort(L, L+N, compare);

		for(int i=0;i<N;i++){
			pos[step][ L[i].index ] = ( (i>0) && (L[i].sort_index_cur_len==L[i-1].sort_index_cur_len) && (L[i].sort_index_next_len==L[i-1].sort_index_next_len) )? pos[step][L[i-1].index] : i;
		}

		doneTill *= 2;
		step += 1;
	}

	/*
	cout << "steps: " << step << endl;
	cout << "Tables after sorting strings with their first " << doneTill << " length" << endl;
	cout << "step: " << step-1 << " doneTill: " << doneTill << endl;
	for(int i=0;i<N;i++)
		cout << pos[step-1][ L[i].index] << '\t' << L[i].index << '\t' << string( s.begin()+L[i].index, s.end() ) << endl;
	cout << endl;
	*/

	int x,y;
	while(1){
		cin >> x >> y;
		cout << lcp(x,y) << endl;
	}

	return 0;
}