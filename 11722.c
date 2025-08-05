#include <stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	int arr[N + 1], dp[N + 1];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = 1;
	}

	int max = 0;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
		}
		if (max < dp[i]) max = dp[i];
	}

	printf("%d", max);
	return 0;
}