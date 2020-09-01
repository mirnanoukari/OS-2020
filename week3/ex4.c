#include <stdio.h>

void swap(int *a, int i, int j) {
	int k = a[i];
	a[i] = a[j];
	a[j] = k;
}

void Q_sort(int *a, int f, int k) {
	if (f >= k) return; 
	int p = a[k];
	int i = f;
	for(int j = f; j < k; j++) {
		if (a[j] <= p) {
			swap(a, i, j);
			i++;
		}
	}
	swap(a, i, k);
	Q_sort(a, f, i-1);
	Q_sort(a, i+1, k);
}

void arr_print(int *a, size_t s) {
	for(int i = 0; i < s; i++) printf("%d ", a[i]);
	printf("\n");
}

void QuickSort(int *a, size_t s) {
	Q_sort(a, 0, s-1);
}

int main() {
	int arr[10] = { 4,3,22,7,5,15,9,8,2,1 };
	arr_print(arr, 10);
	QuickSort(arr, 10);
	arr_print(arr, 10);
	
	return 0;
}
