#include <iostream>
using namespace std;

/*

0 1 2 3 4 5 6 7 8 9
8 9 1 2 7 7 5 0 2 10

*/

int N = 10;

void merge(int a[], int start, int mid, int end){
	int N1 = mid-start+1;
	int N2 = end-mid;

	int first[N1], second[N2];
	int p = 0, q = 0;
	int idx = start;
	for (int i = 0; i < N1; ++i){
		first[i] = a[start+i];
		//cout << first[i] << " ";
	}
	//cout << '\t';
	for (int i = 0; i < N2; ++i){
		second[i] = a[mid+1+i];
		//cout << second[i] << " ";
	}
	//cout << '\t';

	while( (p<N1) || (q<N2)){
		// elements are present in both the parts
		if( (p<N1) && (q<N2)){
			//cout << "p< and q<\n";
			if(first[p] <= second[q]){
				a[idx] = first[p];
				idx++; p++;
			}
			else{
				a[idx] = second[q];
				idx++; q++;
			}
		}
		// elements are present only in the first half
		else if(p<N1){
			//cout << "p<" << idx << "," << p << endl;
			a[idx] = first[p];
			idx++; p++;
		}
		// elements are present only in the second half
		else{
			//cout << "q<" << idx << "," << q << endl;
			a[idx] = second[q];
			idx++; q++;
		}
	}
	return;
}

void mergeSort(int a[], int start, int end){
	int mid = (start+end)/2;
	if (start < mid)
	{
		//cout << "calling mergeSort(a, " << start << ", " << mid << ")\n";
		mergeSort(a, start, mid);	
	}
	if (mid+1 < end)
	{
		//cout << "calling mergeSort(a, " << mid+1 << ", " << end << ")\n";
		mergeSort(a, mid+1, end);	
	}
	//cout << "calling merge(a, " << start << ", " << mid << ", " << end << ")\n";
	merge(a, start, mid, end);
	return;
}

int main(int argc, char const *argv[])
{
	int a[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
	}
	mergeSort(a, 0, N-1);

	for (int i = 0; i < N; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}