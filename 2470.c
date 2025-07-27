#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int N;
	scanf("%d", &N);
	int liq[N + 1];
	for (int i = 0; i < N; i++) scanf("%d", &liq[i]);
	qsort(liq, N, sizeof(int), compare);
	int start = 0, min_start = 0, end = N - 1, min_end = N - 1;
	int min_result = 2000000001;
	while (min_result && start != end) {
		int sum = liq[start] + liq[end];
		if (abs(min_result) > abs(sum)) {
			min_result = sum;
			min_start = start;
			min_end = end;
		}
		if (sum > 0) end--;
		else if (sum < 0) start++;
	}
	printf("%d %d", liq[min_start], liq[min_end]);
	return 0;
}