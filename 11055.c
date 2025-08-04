#include <stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	int arr[N + 1], dp[N + 1];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}

	int max = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < arr[i] + dp[j]) dp[i] = arr[i] + dp[j];
		}
		if (max < dp[i]) max = dp[i];
	}
	printf("%d", max);
	return 0;
}