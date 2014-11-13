#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// store the lefts and rights indexes of intervals
// in each round (total k rounds)
int lt[52], rt[52];

// calculate the probabilities of colors in each round
double pr[52][102];

int main(){
	int t;
	cin >> t;
	while(t--){
		// n: number of balls  , 1 based index
		// c: number of colors , 0 based index
		// k: number of rounds , 0 based index
		int n,c,k;
		cin >> n >> c >> k;

		for(int round=0; round<k; round++)
			cin >> lt[round] >> rt[round];

		// expected sum of all the colors over all the balls 
		double exp_sum = 0.0;

		// for each ball index from 1 to n
		for(int ball=1; ball<=n; ball++){

			// initialize the probabilities to be 0
			memset(pr, 0, sizeof(pr));

			// we know that initially all the balls are coated with 
			// color 1, so probability of color 1 in round 0 = 1
			pr[0][1] = 1.0;

			// number of times the current ball has been chosen
			int n_choosen = 0;

			// for each round
			for(int round=0; round<k; round++){

				// if the current ball is in the range of current round
				if(ball>=lt[round] && ball<=rt[round]){
					//increment the number of times the ball is chosen
					n_choosen++;

					// for each color already exists on the ball
					for(int cur_col=0; cur_col<c; cur_col++){
						// probability that this ball is chosen = 0.5
						// since exactly half of the ways of choosing
						// left and right indexes contains the current ball
						pr[n_choosen][cur_col] += (double)pr[n_choosen-1][cur_col]*0.5;

						// then the chosen ball will be coated randomly by any of the colors
						for(int new_col=0; new_col<c; new_col++){
							// the resulting color will be (cur_col*new_col)%c
							// so we will update the probability for it
							// which is equal to the probability of choosing the current ball
							// (which is equal to prev prob of the ball multiplied by 0.5)
							// multiplied by the probability of coating it with new color = 1/c
							// (can be any color out of c colors)
							pr[n_choosen][(cur_col*new_col)%c] += ((double)pr[n_choosen-1][cur_col])/((double)(2.0*c));
						}
					}
				}
			}

			// sum all the expected values for all the balls for all the colors
			for(int col=0; col<c; col++){
				exp_sum += pr[n_choosen][col]*(double)col;
			}
		}
		cout << fixed;
		cout.precision(7);
		cout << exp_sum << endl;
	}
	return 0;
}