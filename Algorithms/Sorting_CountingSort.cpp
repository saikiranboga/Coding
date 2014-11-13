#include <iostream>
using namespace std;

int N;

void countingSort(int a[], int b[], int k){
	int c[k+1];
	for (int i = 0; i <= k; ++i)
		c[i] = 0;

	for (int i = 0; i < N; ++i)
		c[a[i]]++;
	for (int i = 1; i <= k; ++i)
		c[i] += c[i-1];

	for (int i = N-1; i >= 0; --i)
	{
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}
	return;
}

int main(int argc, char const *argv[])
{
	int k;
	cin >> N >> k;
	int a[N], b[N+1];
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	countingSort(a, b, k);

	for (int i = 1; i <= N; ++i)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}