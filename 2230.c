#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int seq[n + 1];
	for (int i = 0; i < n; i++) scanf("%d", &seq[i]);
	qsort(seq, n, sizeof(int), compare);

	int start = 0, end = 0;
	int min_diff = 2000000001;

	while (end < n) {
		int diff = seq[end] - seq[start];
		if (diff < m) end++;
		else {
			if (diff < min_diff) min_diff = diff;
			if (diff == m) break;
			start++;
		}
	}
	printf("%d", min_diff);
	return 0;
}