#include <iostream>
using namespace std;

int N;

void insertionSort(int a[]){
	int key, i;
	if (N > 1)
	{
		for (int j = 1; j < N; ++j)
		{
			key = a[j];
			for (i = j-1; i >= 0 && a[i] > key; --i)
			{
				a[i+1] = a[i];
			}
			a[i+1] = key;
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	cin >> N;
	int a[N];
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	insertionSort(a);

	for (int i = 0; i < N; ++i)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}