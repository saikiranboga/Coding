#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int ar[n];
	for(int i=0; i<n; i++)
		cin >> ar[i];
	
	int pos = 0;
	char type;
	int x;

	for(int i=0; i<m; i++)
	{
		cin >> type >> x;
		if(type == 'A')
		{
			pos = (pos + x) % n;
		}
		else if(type == 'C')
		{
			pos = (pos - x + n) % n;
		}
		else
		{
			x--;
			if(x >= pos)
				cout << ar[ x-pos ] << endl;
			else
				cout << ar[ n - pos + x ] << endl;
		}
	}
	return 0;
}