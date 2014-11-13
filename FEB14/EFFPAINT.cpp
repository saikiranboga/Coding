#include <cstdio>
#include <vector>
using namespace std;

int N;
// the original grid
char grid[50][51];
// corners of the grid
// each bit represents the parity of the corner - true if the corner is
// adjacent to an odd number of black cells, false if the corner is adjacent
// to an even number of black cells.
bool corners[51][51];

struct rect{
	int x1, y1, x2, y2;
	char c;
	rect(int x1, int y1, int x2, int y2, char c): x1(x1), y1(y1), x2(x2), y2(y2), c(c){}
	void print(){
		printf("%d %d %d %d %c\n", y1, x1, y2, x2, c);
	}
};

// the solution itself
vector<rect> sol;

void solve(){
	for(int y1=0; y1<N; y1++){
		// greedily remove rectangles.
		// on the first pass only remove rectangles if all 4 corners
		// have odd parity.  on the second pass remove rectangles
		// if 3 of the 4 corners (exclude the bottom-right) have odd
		// parity.
		for(int pass=0; pass<2; pass++){
			for(int y2=y1; y2<N; y2++)
			for(int x1=0; x1<N; x1++)
			for(int x2=x1; x2<N; x2++){
				if(corners[y1][x1] && corners[y1][x2+1] && corners[y2+1][x1] && (pass==1 || corners[y2+1][x2+1])){
					sol.push_back(rect(x1, y1, x2, y2, 'F'));
					// performing a 'F' operation changes
					// the parity of exactly 4 corners
					corners[y1][x1]^=1;
					corners[y2+1][x1]^=1;
					corners[y1][x2+1]^=1;
					corners[y2+1][x2+1]^=1;
				}
			}
		}
	}
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", grid[i]);
		for(int j=0; j<N; j++){
			if(grid[i][j]=='B'){
				// change the parity of the 4 corners adjacent
				// to this cell
				corners[i][j]^=1;
				corners[i][j+1]^=1;
				corners[i+1][j]^=1;
				corners[i+1][j+1]^=1;
			}
		}
	}
	solve();
	printf("%d\n", sol.size());
	for(int i=0; i<sol.size(); i++)
		sol[i].print();
	return 0;
}
