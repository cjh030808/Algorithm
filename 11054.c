#include <stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	int arr[N], rdp[N], ldp[N], dp[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		rdp[i] = 1;
		ldp[i] = 1;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && rdp[i] < rdp[j] + 1) rdp[i] = rdp[j] + 1;
		}
	}
	for (int i = N - 2; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (arr[i] > arr[j] && ldp[i] < ldp[j] + 1) ldp[i] = ldp[j] + 1;
		}
	}

	int max = -1;
	for (int i = 0; i < N; i++) {
		dp[i] = rdp[i] + ldp[i];
		if (max < dp[i]) max = dp[i];
	}
	printf("%d", max - 1);

	return 0;
}