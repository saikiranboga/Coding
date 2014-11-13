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



int intersect[51][51][51][51];

int main(){
	int n, m=0;
	cin >> n;
	vector< pair<int,int> > pts(n);
	
	for(int i=0;i<n;i++)
		cin >> pts[i].first >> pts[i].second;

	string s;
	int edges[n][n];
	
	Node degrees[n];


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
								//cout << "intersect: " << i << " " << j << " " << k << " " << l << endl;
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
	int out[1000][100];
	int out_idx = 0;

	while(num_edges){

		sort(degrees, degrees+n, compare);

		int cur, cur_idx;
		for(int i=0;i<n;i++){
			if(degrees[i].degree > 0){
				cur = degrees[i].pt_no;
				cur_idx = i;
			}
		}
		int degree_p2, degree_p1;
		int p1, p2;
		if(degrees[cur_idx].degree >= 2){
			p1=-1, p2=-1;
			for(int i=0;i<n && p2==-1;i++){
				if(edges[cur][i]){
					if(p1==-1)
						p1 = i;
					else
						p2 = i;
				}
			}
			out[out_idx][0] = 2;
			out[out_idx][1] = p1;
			out[out_idx][2] = cur;
			out[out_idx][3] = p2;
			
			num_edges -= 2;
			edges[cur][p1] = 0;
			edges[p1][cur] = 0;

			edges[cur][p2] = 0;
			edges[p2][cur] = 0;

			degrees[cur_idx].degree -= 2;
			for(int j=0;j<n;j++){
				if(degrees[j].pt_no == p1){
					degrees[j].degree -= 1;
					degree_p1 = degrees[j].degree;
				}
				else if(degrees[j].pt_no == p2){
					degrees[j].degree -= 1;
					degree_p2 = degrees[j].degree;
				}
			}

			while(degree_p2 >= 1){
				int prev_elems = out[out_idx][0];

				// SEE IF ANY >=2 DEGREE NODES AVAILABLE
				int node_of_degree_g2, node_of_degree_g2_processed = 0;
				for(int j=0;j<n;j++){
					node_of_degree_g2 = 0;
					if(edges[p2][j]){
						for(int deg=0;deg<n;deg++){
							if(degrees[deg].pt_no == j)
								if(degrees[deg].degree > 1){
									node_of_degree_g2 = 1;
									break;
								}

						}

						if(node_of_degree_g2){

							int intsx = 0;
						
							//checking whether it intersects with any segments of the path
							int elm = out[out_idx][0];
							for(int sx=1; sx<elm; sx++){
								//cout << p2 << " " << j << " checking for: " << out[out_idx][sx] << ", " << out[out_idx][sx+1] << endl;
								if( (j==out[out_idx][sx]) || (j==out[out_idx][sx+1]) || (intersect[ out[out_idx][sx] ][ out[out_idx][sx+1] ][p2][j] ) ){
									intsx = 1;
									break;
								}
							}
							//end

							if(!intsx){
								out[out_idx][0]++;
								//cout << "num of elems: " << out[out_idx][0] << endl;
								out[out_idx][out[out_idx][0]+1] = j;
								/*
								for(int ll=1;ll<=out[out_idx][0]+1;ll++)
									cout << out[out_idx][ll] << " ";
								cout << endl;
								*/
								num_edges -= 1;
								edges[p2][j] = 0;
								edges[j][p2] = 0;

								for(int jj=0;jj<n;jj++){
									if(degrees[jj].pt_no == p2)
										degrees[jj].degree -= 1;
									else if(degrees[jj].pt_no == j){
										degrees[jj].degree -= 1;
										degree_p2 = degrees[jj].degree;
									}
								}
								//cout << "changing " << p2 << " to " << j << endl;
								p2 = j;
								node_of_degree_g2_processed = 1;
								break;
							}
						}
					}
				}


				// END


				// IF NO NODE OF DEGREE >= 2 EXISTS THEN CONTINUE WITH OTHER OPTIONS

				if(!node_of_degree_g2_processed){

					for(int j=0;j<n;j++){

						if(edges[p2][j]){

							int intsx = 0;
						
							//checking whether it intersects with any segments of the path
							int elm = out[out_idx][0];
							for(int sx=1; sx<elm; sx++){
								//cout << p2 << " " << j << " checking for: " << out[out_idx][sx] << ", " << out[out_idx][sx+1] << endl;
								if( (j==out[out_idx][sx]) || (j==out[out_idx][sx+1]) || (intersect[ out[out_idx][sx] ][ out[out_idx][sx+1] ][p2][j] ) ){
									intsx = 1;
									break;
								}
							}
							//end

							if(!intsx){
								out[out_idx][0]++;
								//cout << "num of elems: " << out[out_idx][0] << endl;
								out[out_idx][out[out_idx][0]+1] = j;
								/*
								for(int ll=1;ll<=out[out_idx][0]+1;ll++)
									cout << out[out_idx][ll] << " ";
								cout << endl;
								*/
								num_edges -= 1;
								edges[p2][j] = 0;
								edges[j][p2] = 0;

								for(int jj=0;jj<n;jj++){
									if(degrees[jj].pt_no == p2)
										degrees[jj].degree -= 1;
									else if(degrees[jj].pt_no == j){
										degrees[jj].degree -= 1;
										degree_p2 = degrees[jj].degree;
									}
								}
								//cout << "changing " << p2 << " to " << j << endl;
								p2 = j;
								break;
							}
						}
					}
				}
				if(prev_elems == out[out_idx][0])
					degree_p2 = 0;
			}

			// REVERSE THE LIST SO FAR TO EXTEND THE PATH FROM OTHER END TOO!! :)
			reverse( out[out_idx]+1, out[out_idx]+out[out_idx][0]+2 );

			// USE SAME CODE AS ABOVE TO BY JUST CHANING WHAT p2 IS!
			int path_start = p2;
			degree_p2 = degree_p1;
			p2 = p1;

			while(degree_p2 >= 1){
				int prev_elems = out[out_idx][0];

				// SEE IF ANY >=2 DEGREE NODES AVAILABLE
				int node_of_degree_g2, node_of_degree_g2_processed = 0;
				for(int j=0;j<n;j++){
					node_of_degree_g2 = 0;
					if(edges[p2][j]){
						for(int deg=0;deg<n;deg++){
							if(degrees[deg].pt_no == j)
								if(degrees[deg].degree > 1){
									node_of_degree_g2 = 1;
									break;
								}

						}

						if(node_of_degree_g2){

							int intsx = 0;
						
							//checking whether it intersects with any segments of the path
							int elm = out[out_idx][0];
							for(int sx=1; sx<elm; sx++){
								//cout << p2 << " " << j << " checking for: " << out[out_idx][sx] << ", " << out[out_idx][sx+1] << endl;
								if( (j==out[out_idx][sx]) || (j==out[out_idx][sx+1]) || (intersect[ out[out_idx][sx] ][ out[out_idx][sx+1] ][p2][j] ) ){
									intsx = 1;
									break;
								}
							}
							//end

							if(!intsx){
								out[out_idx][0]++;
								//cout << "num of elems: " << out[out_idx][0] << endl;
								out[out_idx][out[out_idx][0]+1] = j;
								/*
								for(int ll=1;ll<=out[out_idx][0]+1;ll++)
									cout << out[out_idx][ll] << " ";
								cout << endl;
								*/
								num_edges -= 1;
								edges[p2][j] = 0;
								edges[j][p2] = 0;

								for(int jj=0;jj<n;jj++){
									if(degrees[jj].pt_no == p2)
										degrees[jj].degree -= 1;
									else if(degrees[jj].pt_no == j){
										degrees[jj].degree -= 1;
										degree_p2 = degrees[jj].degree;
									}
								}
								//cout << "changing " << p2 << " to " << j << endl;
								p2 = j;
								node_of_degree_g2_processed = 1;
								break;
							}
						}
					}
				}


				// END


				// IF NO NODE OF DEGREE >= 2 EXISTS THEN CONTINUE WITH OTHER OPTIONS

				if(!node_of_degree_g2_processed){

					for(int j=0;j<n;j++){

						if(edges[p2][j]){

							int intsx = 0;
						
							//checking whether it intersects with any segments of the path
							int elm = out[out_idx][0];
							for(int sx=1; sx<elm; sx++){
								//cout << p2 << " " << j << " checking for: " << out[out_idx][sx] << ", " << out[out_idx][sx+1] << endl;
								if( (j==out[out_idx][sx]) || (j==out[out_idx][sx+1]) || (intersect[ out[out_idx][sx] ][ out[out_idx][sx+1] ][p2][j] ) ){
									intsx = 1;
									break;
								}
							}
							//end

							if(!intsx){
								out[out_idx][0]++;
								//cout << "num of elems: " << out[out_idx][0] << endl;
								out[out_idx][out[out_idx][0]+1] = j;
								/*
								for(int ll=1;ll<=out[out_idx][0]+1;ll++)
									cout << out[out_idx][ll] << " ";
								cout << endl;
								*/
								num_edges -= 1;
								edges[p2][j] = 0;
								edges[j][p2] = 0;

								for(int jj=0;jj<n;jj++){
									if(degrees[jj].pt_no == p2)
										degrees[jj].degree -= 1;
									else if(degrees[jj].pt_no == j){
										degrees[jj].degree -= 1;
										degree_p2 = degrees[jj].degree;
									}
								}
								//cout << "changing " << p2 << " to " << j << endl;
								p2 = j;
								break;
							}
						}
					}
				}
				if(prev_elems == out[out_idx][0])
					degree_p2 = 0;
			}

			// STORING END OF PATH
			int path_end = p2;

			// CHECK IF THE PATH CAN FORM A LOOP
			if(edges[path_end][path_start]){

				//checking whether it intersects with any segments of the path
				int elm = out[out_idx][0];
				int intsx = 0;
				for(int sx=1; sx<elm; sx++){
					//cout << p2 << " " << j << " checking for: " << out[out_idx][sx] << ", " << out[out_idx][sx+1] << endl;
					if( intersect[ out[out_idx][sx] ][ out[out_idx][sx+1] ][path_end][path_start] ){
						intsx = 1;
						break;
					}
				}
				//end
				if(!intsx){
					out[out_idx][0]++;
					out[out_idx][out[out_idx][0]+1] = path_start;
					num_edges -= 1;
					edges[path_end][path_start] = 0;
					edges[path_start][path_end] = 0;

					for(int jj=0;jj<n;jj++){
						if(degrees[jj].pt_no == path_end)
							degrees[jj].degree -= 1;
						else if(degrees[jj].pt_no == path_start)
							degrees[jj].degree -= 1;
					}
				}
			}

			out_idx++;

		}
		else if(degrees[cur_idx].degree == 1){
			p1=-1, p2=-1;
			for(int i=0;i<n && p1==-1;i++)
				if(edges[cur][i])
					p1 = i;
			out[out_idx][0] = 1;
			out[out_idx][1] = cur;
			out[out_idx][2] = p1;
			//out_idx++;
			num_edges -= 1;
			edges[cur][p1] = 0;
			edges[p1][cur] = 0;

			degrees[cur_idx].degree -= 1;
			degree_p1 = degrees[cur_idx].degree;
			for(int j=0;j<n;j++){
				if(degrees[j].pt_no == p1){
					degrees[j].degree -= 1;
					degree_p2 = degrees[j].degree;
				}

			}

			p1 = cur;
			p2 = p1;

			while(degree_p2 >= 1){
				int prev_elems = out[out_idx][0];

				// SEE IF ANY >=2 DEGREE NODES AVAILABLE
				int node_of_degree_g2, node_of_degree_g2_processed = 0;
				for(int j=0;j<n;j++){
					node_of_degree_g2 = 0;
					if(edges[p2][j]){
						for(int deg=0;deg<n;deg++){
							if(degrees[deg].pt_no == j)
								if(degrees[deg].degree > 1){
									node_of_degree_g2 = 1;
									break;
								}

						}

						if(node_of_degree_g2){

							int intsx = 0;
						
							//checking whether it intersects with any segments of the path
							int elm = out[out_idx][0];
							for(int sx=1; sx<elm; sx++){
								//cout << p2 << " " << j << " checking for: " << out[out_idx][sx] << ", " << out[out_idx][sx+1] << endl;
								if( (j==out[out_idx][sx]) || (j==out[out_idx][sx+1]) || (intersect[ out[out_idx][sx] ][ out[out_idx][sx+1] ][p2][j] ) ){
									intsx = 1;
									break;
								}
							}
							//end

							if(!intsx){
								out[out_idx][0]++;
								//cout << "num of elems: " << out[out_idx][0] << endl;
								out[out_idx][out[out_idx][0]+1] = j;
								/*
								for(int ll=1;ll<=out[out_idx][0]+1;ll++)
									cout << out[out_idx][ll] << " ";
								cout << endl;
								*/
								num_edges -= 1;
								edges[p2][j] = 0;
								edges[j][p2] = 0;

								for(int jj=0;jj<n;jj++){
									if(degrees[jj].pt_no == p2)
										degrees[jj].degree -= 1;
									else if(degrees[jj].pt_no == j){
										degrees[jj].degree -= 1;
										degree_p2 = degrees[jj].degree;
									}
								}
								//cout << "changing " << p2 << " to " << j << endl;
								p2 = j;
								node_of_degree_g2_processed = 1;
								break;
							}
						}
					}
				}


				// END


				// IF NO NODE OF DEGREE >= 2 EXISTS THEN CONTINUE WITH OTHER OPTIONS

				if(!node_of_degree_g2_processed){

					for(int j=0;j<n;j++){

						if(edges[p2][j]){

							int intsx = 0;
						
							//checking whether it intersects with any segments of the path
							int elm = out[out_idx][0];
							for(int sx=1; sx<elm; sx++){
								//cout << p2 << " " << j << " checking for: " << out[out_idx][sx] << ", " << out[out_idx][sx+1] << endl;
								if( (j==out[out_idx][sx]) || (j==out[out_idx][sx+1]) || (intersect[ out[out_idx][sx] ][ out[out_idx][sx+1] ][p2][j] ) ){
									intsx = 1;
									break;
								}
							}
							//end

							if(!intsx){
								out[out_idx][0]++;
								//cout << "num of elems: " << out[out_idx][0] << endl;
								out[out_idx][out[out_idx][0]+1] = j;
								/*
								for(int ll=1;ll<=out[out_idx][0]+1;ll++)
									cout << out[out_idx][ll] << " ";
								cout << endl;
								*/
								num_edges -= 1;
								edges[p2][j] = 0;
								edges[j][p2] = 0;

								for(int jj=0;jj<n;jj++){
									if(degrees[jj].pt_no == p2)
										degrees[jj].degree -= 1;
									else if(degrees[jj].pt_no == j){
										degrees[jj].degree -= 1;
										degree_p2 = degrees[jj].degree;
									}
								}
								//cout << "changing " << p2 << " to " << j << endl;
								p2 = j;
								break;
							}
						}
					}
				}
				if(prev_elems == out[out_idx][0])
					degree_p2 = 0;
			}

			// REVERSE THE LIST SO FAR TO EXTEND THE PATH FROM OTHER END TOO!! :)
			reverse( out[out_idx]+1, out[out_idx]+out[out_idx][0]+2 );

			// USE SAME CODE AS ABOVE TO BY JUST CHANING WHAT p2 IS!
			int path_start = p2;
			degree_p2 = degree_p1;
			p2 = p1;

			while(degree_p2 >= 1){
				int prev_elems = out[out_idx][0];

				// SEE IF ANY >=2 DEGREE NODES AVAILABLE
				int node_of_degree_g2, node_of_degree_g2_processed = 0;
				for(int j=0;j<n;j++){
					node_of_degree_g2 = 0;
					if(edges[p2][j]){
						for(int deg=0;deg<n;deg++){
							if(degrees[deg].pt_no == j)
								if(degrees[deg].degree > 1){
									node_of_degree_g2 = 1;
									break;
								}

						}

						if(node_of_degree_g2){

							int intsx = 0;
						
							//checking whether it intersects with any segments of the path
							int elm = out[out_idx][0];
							for(int sx=1; sx<elm; sx++){
								//cout << p2 << " " << j << " checking for: " << out[out_idx][sx] << ", " << out[out_idx][sx+1] << endl;
								if( (j==out[out_idx][sx]) || (j==out[out_idx][sx+1]) || (intersect[ out[out_idx][sx] ][ out[out_idx][sx+1] ][p2][j] ) ){
									intsx = 1;
									break;
								}
							}
							//end

							if(!intsx){
								out[out_idx][0]++;
								//cout << "num of elems: " << out[out_idx][0] << endl;
								out[out_idx][out[out_idx][0]+1] = j;
								/*
								for(int ll=1;ll<=out[out_idx][0]+1;ll++)
									cout << out[out_idx][ll] << " ";
								cout << endl;
								*/
								num_edges -= 1;
								edges[p2][j] = 0;
								edges[j][p2] = 0;

								for(int jj=0;jj<n;jj++){
									if(degrees[jj].pt_no == p2)
										degrees[jj].degree -= 1;
									else if(degrees[jj].pt_no == j){
										degrees[jj].degree -= 1;
										degree_p2 = degrees[jj].degree;
									}
								}
								//cout << "changing " << p2 << " to " << j << endl;
								p2 = j;
								node_of_degree_g2_processed = 1;
								break;
							}
						}
					}
				}


				// END


				// IF NO NODE OF DEGREE >= 2 EXISTS THEN CONTINUE WITH OTHER OPTIONS

				if(!node_of_degree_g2_processed){

					for(int j=0;j<n;j++){

						if(edges[p2][j]){

							int intsx = 0;
						
							//checking whether it intersects with any segments of the path
							int elm = out[out_idx][0];
							for(int sx=1; sx<elm; sx++){
								//cout << p2 << " " << j << " checking for: " << out[out_idx][sx] << ", " << out[out_idx][sx+1] << endl;
								if( (j==out[out_idx][sx]) || (j==out[out_idx][sx+1]) || (intersect[ out[out_idx][sx] ][ out[out_idx][sx+1] ][p2][j] ) ){
									intsx = 1;
									break;
								}
							}
							//end

							if(!intsx){
								out[out_idx][0]++;
								//cout << "num of elems: " << out[out_idx][0] << endl;
								out[out_idx][out[out_idx][0]+1] = j;
								/*
								for(int ll=1;ll<=out[out_idx][0]+1;ll++)
									cout << out[out_idx][ll] << " ";
								cout << endl;
								*/
								num_edges -= 1;
								edges[p2][j] = 0;
								edges[j][p2] = 0;

								for(int jj=0;jj<n;jj++){
									if(degrees[jj].pt_no == p2)
										degrees[jj].degree -= 1;
									else if(degrees[jj].pt_no == j){
										degrees[jj].degree -= 1;
										degree_p2 = degrees[jj].degree;
									}
								}
								//cout << "changing " << p2 << " to " << j << endl;
								p2 = j;
								break;
							}
						}
					}
				}
				if(prev_elems == out[out_idx][0])
					degree_p2 = 0;
			}

			// STORING END OF PATH
			int path_end = p2;

			// CHECK IF THE PATH CAN FORM A LOOP
			if(edges[path_end][path_start]){

				//checking whether it intersects with any segments of the path
				int elm = out[out_idx][0];
				int intsx = 0;
				for(int sx=1; sx<elm; sx++){
					//cout << p2 << " " << j << " checking for: " << out[out_idx][sx] << ", " << out[out_idx][sx+1] << endl;
					if( intersect[ out[out_idx][sx] ][ out[out_idx][sx+1] ][path_end][path_start] ){
						intsx = 1;
						break;
					}
				}
				//end
				if(!intsx){
					out[out_idx][0]++;
					out[out_idx][out[out_idx][0]+1] = path_start;
					num_edges -= 1;
					edges[path_end][path_start] = 0;
					edges[path_start][path_end] = 0;

					for(int jj=0;jj<n;jj++){
						if(degrees[jj].pt_no == path_end)
							degrees[jj].degree -= 1;
						else if(degrees[jj].pt_no == path_start)
							degrees[jj].degree -= 1;
					}
				}
			}

			out_idx++;

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


	// CHECK IF ANY TOURS CAN BE MERGED
	int merge_possible = 0;
	for(int i=0;i<out_idx;i++){
		int len1 = out[i][0];
		int start1 = out[i][1];
		int end1 = out[i][len1+1];
		int j;
		if(len1==1){
			for(j=0;j<out_idx;j++){
				merge_possible = 1;
				if(i!=j){
					int len2 = out[j][0];
					int start2 = out[j][1];
					int end2 = out[j][len2+1];
				
					if(end1 == start2){
						for(int ii=2;ii<=len2;ii++){
							if(intersect[out[j][ii]][out[j][ii+1]][start1][end1]){
								merge_possible = 0;
								break;	
							}
						}
					}
					else if(end2 == start1){
						for(int ii=2;ii<=len2;ii++){
							if(intersect[out[j][ii]][out[j][ii+1]][start1][end1]){
								merge_possible = 0;
								break;	
							}
						}
					}
				}
				merge_possible = 0;
			}
		}
		if(merge_possible){
			cout << "merge_possible between: " << i << " " << j << endl;
			//while(1){
			//}
		}
	}
	
	// END

	return 0;
}

/*

tests:
9
0 0
1 0
1 1
0 1
-1 -1
-1 0
-1 -1
0 -1
1 -1
NYYYYYYYY
YNNNNNNNN
YNNNNNNNN
YNNNNNNNN
YNNNNNNNN
YNNNNNNNN
YNNNNNNNN
YNNNNNNNN
YNNNNNNNN

6
2 3
10 0
10 7
3 7
9 8
2 1
NNNYNY
NNYYNN
NYNYYN
YYYNYN
NNYYNY
YNNNYN

4
0 0
1 0
1 1
0 1
NYNN
YNYN
NYNY
NNYN

4
-1 0
1 0
0 1
0 -1
NYYY
YNYY
YYNY
YYYN

4
0 1
-1 0
1 0
0 -1
NYYN
YNYY
YYNY
NYYN

6
0 0
1 0
1 -1
0 -1
0 -2
1 -2
NYNNNN
YNYNNN
NYNYNN
NNYNYN
NNNYNY
NNNNYN

7
0 0
2 0
2 -1
1 1
0 -1
0 -2
2 -2
NYNNNNN
YNYNNNN
NYNYNNN
NNYNYNN
NNNYNYN
NNNNYNY
NNNNNYN

5
1 1
4 7
7 1
2 5
6 5
NYNNY
YNYNN
NYNYN
NNYNY
YNNYN

4
0 0
0 1
1 0
1 1
NYNN
YNNN
NNNY
NNYN
*/