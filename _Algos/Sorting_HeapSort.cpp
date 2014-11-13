#include <iostream>
using namespace std;

int N, heap_size;

int parent(int i){
	return i/2;
}

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i + 1;
}

void swap(int* a, int*b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int a[]){
	for (int i = 1; i <= N; ++i)
		cout << a[i] << " ";
	cout << endl;
}

void maxHeapify(int a[], int i){
	int l = left(i);
	int r = right(i);
	int largest = 0;
	if(l <= heap_size && a[l] > a[i])
		largest = l;
	else
		largest = i;

	if (r <= heap_size && a[r] > a[largest])
		largest = r;
	
	if(largest != i){
		swap(a[i], a[largest]);
		maxHeapify(a, largest);
	}
}

void buildMaxHeap(int a[]){
	heap_size = N;
	for (int i = N/2; i >= 1; --i)
	{
		maxHeapify(a, i);
	}
}

void heapSort(int a[]){
	buildMaxHeap(a);
	for (int i = N; i > 1; --i)
	{
		//print(a);
		swap(&a[1], &a[i]);
		heap_size = heap_size-1;
		maxHeapify(a, 1);
	}
}

int main(int argc, char const *argv[])
{
	cin >> N;
	int a[N+1];
	a[0] = 0;

	for (int i = 1; i <= N; ++i)
		cin >> a[i];

	heapSort(a);
	print(a);
	return 0;
}
