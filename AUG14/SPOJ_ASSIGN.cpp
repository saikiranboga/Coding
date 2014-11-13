#include <bits/stdc++.h>
using namespace std;

int adj[21][21], N;
long long f[1048576];

int main()
{
	int T;
	cin >> T;

	for (int cs = 1; cs <= T; cs++) {
		cin >> N;
		memset(adj, 0, sizeof(adj));
		string line;
		int x;
		for(int i=0;i<N;i++){
			getline(cin, line);
			istringstream is(line);
			while(is >> x){
				adj[i][x-1] = 1;
			}
		}

		f[(1<<N)-1] = 1;

		for (int mask = (1<<N)-2; mask >= 0; mask--) {
			int k = 0;
			for (int i = 0; i < N; i++)
				k += (mask >> i) & 1;

			f[mask] = 0;
			for (int s = 0; s < N; s++)
				if (adj[k][s] == 1 && (mask & (1 << s)) == 0)
					f[mask] += f[mask | (1 << s)];
		}

		cout << f[0] << endl;
	}
}