#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int n, x;
	int result = 0;
	scanf("%d", &n);
	int arr[n + 1];
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	scanf("%d", &x);
	qsort(arr, n, sizeof(int), compare);

	int p1 = 0, p2 = n - 1;
	while (p1 < p2) {
		int tmp = arr[p1] + arr[p2];
		if (tmp == x) result++;
		else if (tmp < x) p1++;
		else p2--;
	}
	printf("%d", result);

	return 0;
}