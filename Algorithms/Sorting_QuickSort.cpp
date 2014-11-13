#include <iostream>
using namespace std;

int N = 10;

void qSort(int a[], int start, int end){
	int left = start;
	int right = end;
	int mid = (start+end)/2;
	int pivot = a[mid];
	int temp;
	do{
		while(left <= end && a[left] <= pivot)
			left++;
		while(right >= start && a[right] > pivot)
			right--;
		if(left <= right){
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;

			left++;
			right--;
		}
	}while(left <= right);
	if(left < end)
		qSort(a, left, end);
	if(right > start){
		temp = a[right];
		a[right] = pivot;
		a[mid] = temp;
		right--;
		if(right > start)
			qSort(a, start, right);
	}
	return;
}

int main(int argc, char const *argv[])
{
	int a[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
	}

	qSort(a, 0, N-1);

	for (int i = 0; i < N; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}