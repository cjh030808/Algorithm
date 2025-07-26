#include <stdio.h>
int main() {
	int N, S; 
	scanf("%d %d", &N, &S);
	int arr[N + 1];
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	long long total_sum = 0;
	int min_len = 100001, len = 0;
	int start = 0;
	for (int i = 0; i < N; i++) {
		total_sum += arr[i];
		len++;
		while (total_sum >= S) {
			if (min_len > len) min_len = len;
			total_sum -= arr[start++];
			len--;
		}
	}
	if (min_len == 100001) {
		printf("0");
		return 0;
	}
	printf("%d", min_len);
	return 0; 
}