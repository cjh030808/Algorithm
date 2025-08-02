#include <stdio.h>
#define MAX 4000000

int isPrime(int n) {
	if (n <= 1) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	int N;
	scanf("%d", &N);
	int arr[N];
	int j = 0;
	for (int i = 1; i <= N; i++) {
		if (isPrime(i)) arr[j++] = i;
	}
	int left = 0, right = 0;
	int result = 0;
	while (right < j) {
		int tmp = 0;
		for (int i = left; i <= right; i++) tmp += arr[i];

		if (tmp == N) { 
			result += 1;
			right += 1;
		}
		else if (tmp > N) left += 1;
		else right += 1;
	}
	printf("%d", result);

	return 0;
}