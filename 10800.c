#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ball {
	int idx;
	int color;
	int size;
} ball;

int compare(const void* a, const void* b) {
	ball A = *(ball*)a;
	ball B = *(ball*)b;
	return A.size - B.size;
}

int main() {
	int n;
	scanf("%d", &n);
	ball arr[n + 1];
	int result[n];
	int color_sum[n + 1];
	int total_sum = 0;

	memset(color_sum, 0, sizeof(color_sum));
	memset(result, 0, sizeof(result));

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].color, &arr[i].size);
		arr[i].idx = i;
	}
	int sum = 0;
	qsort(arr, n, sizeof(ball), compare);

	int j = 0;
	for (int i = 0; i < n; i++) {
		while (arr[j].size < arr[i].size) {
			total_sum += arr[j].size;
			color_sum[arr[j].color] += arr[j].size;
			j++;
		}
		result[arr[i].idx] = total_sum - color_sum[arr[i].color];
	}
	for (int i = 0; i < n; i++) printf("%d\n", result[i]);
	

	return 0;
}