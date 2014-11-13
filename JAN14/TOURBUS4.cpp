#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef struct Node{
	int pt_no;
	int degree;
}Node;

int compare(const Node& a, const Node& b){
	return ( a.degree > b.degree );
}

// CODE TO CHECK IF TWO SEGMENTS INTERSECT

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(pair<int,int> p, pair<int,int> q, pair<int,int> r)
{
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
        q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
       return true;
 
    return false;
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(pair<int,int> p, pair<int,int> q, pair<int,int> r)
{
    // See 10th slides from following link for derivation of the formula
    // http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
    int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
 
    if (val == 0) return 0;  // colinear
 
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(pair<int,int> p1, pair<int,int> q1, pair<int,int> p2, pair<int,int> q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}


// END

int n, m=0;

int edges[51][51];
int intersect[51][51][51][51];
Node degrees[51];
vector< pair<int,int> > pts(51);

int out[1000][100];
int out_idx = 0;

// remove passing parameter cur_path and try to store each optimal node at every position or in some other way
// this is not working, if possible try and improve this.


int findPath(int cur, int cur_path[], int pos){

	int max_node = -1, max_len = 0;
	int len = 0;
	int this_node = -1;
	int incl, end = 1;
	int max_path[1000];
	for(int i=0;i<n;i++){
		incl = 0;
		if(edges[cur][i]){
			incl = 1;
			//checking for intersection
			for(int j=1;j<=cur_path[0];j++){
				if( (cur_path[j]==i) || (cur_path[j+1]==i) || (intersect[cur_path[j]][cur_path[j+1]][cur][i]) ) {
					incl = 0;
					break;
				}
			}
			//cout << incl << endl;
			if(incl == 1){
				//cout << cur << ", " << i << endl;

				cur_path[0] += 1;
				cur_path[ pos ] = i;

				edges[cur][i] = 0;
				edges[i][cur] = 0;

				cout << cur << " calling: " << i << ", " << cur_path[0] << ", " << pos+1 << endl;
				
				len = 1+findPath(i, cur_path, pos+1);

				cout << i << " length returned: " << len << endl;

				edges[cur][i] = 1;
				edges[i][cur] = 1;
				cur_path[0] -= 1;
			
				if(len > max_len){

					max_len = len;
					max_node = i;
					//for(int j=pos;j<pos+max_len;j++)
					//	max_path[j-pos] = cur_path[pos];
				}
			}
		}
	}
	//cur_path[0] = pos + max_len - 1;
	//for(int i=pos;i<pos+max_len;i++){
	//	cur_path[i] = max_path[i-pos];
	//}
	cout << cur << " connected to " << max_node << endl;
	if(max_node != -1){
		cur_path[pos] = max_node;
		return max_len;
	}
	else
		return 0;
}


int main(){
	cin >> n;
	
	for(int i=0;i<n;i++)
		cin >> pts[i].first >> pts[i].second;

	string s;

	for(int i=0;i<n;i++){
		degrees[i].pt_no = i;
		degrees[i].degree = 0;
		cin >> s;
		
		for(int j=0;j<n;j++){
			if(s[j] == 'Y'){
				edges[i][j] = 1;
				degrees[i].degree += 1;
				m++;
			}
			else
				edges[i][j] = 0;
		}
		
	}

//FINDING INTERSECTION BETWEEN ALL LINE SEGMENTS

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
					for(int l=0; l<n; l++)
						intersect[i][j][k][l] = 0;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			
			if(edges[i][j]){
				for(int k=0; k<n; k++){
					for(int l=0; l<n; l++){
						if(i!=k && i!=l && j!=k && j!=l && edges[k][l]){
							if( doIntersect(pts[i], pts[j], pts[k], pts[l]) ){
								intersect[i][j][k][l] = 1;
							}
						}
					}
				}
			}

		}
	}

//END

	m /= 2;
	int num_edges = m;
	int cur = 0;
	int cur_path[1000];
	while(num_edges > 0){
		for(int i=0;i<n;i++){
			if(degrees[i].degree > 0){
				cur = i;
				cur_path[0] = 0;
				cur_path[1] = i;

				cur_path[0] = findPath(cur, cur_path, 2);
				out[out_idx][0] = cur_path[0];
				
				for(int j=1;j<=cur_path[0];j++){
					degrees[ cur_path[j] ].degree -= 1;
					degrees[ cur_path[j+1] ].degree -= 1;
					edges[ cur_path[j] ][ cur_path[j+1] ] = 0;
					edges[ cur_path[j+1] ][ cur_path[j] ] = 0;
					num_edges -= cur_path[0];

					out[out_idx][j] = cur_path[j];
				}
				out_idx++;
				num_edges = -1;
			}
		}
	}

	int n_p;
	cout << out_idx << endl;
	for(int i=0;i<out_idx;i++){
		cout << out[i][0] << " ";
		n_p = out[i][0] + 1;
		for(int j=1;j<=n_p;j++)
			cout << out[i][j] << " ";
		cout << endl;
	}

	return 0;
}