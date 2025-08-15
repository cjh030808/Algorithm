#include <stdio.h>
#include <string.h>
#define MAX 1000

int main() {
	char first[MAX + 1], second[MAX + 1];
	scanf("%s %s", first, second);
	int f_len = strlen(first), s_len = strlen(second);
	int LCS[f_len + 2][s_len + 2]; // 0, '0'

	int result = 0;
	for (int i = 0; i <= f_len; i++) {
		for (int j = 0; j <= s_len; j++) {
			if (i == 0 || j == 0) LCS[i][j] = 0;
			else if (first[i - 1] == second[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else LCS[i][j] = LCS[i - 1][j] > LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1];

			if (LCS[i][j] > result) result = LCS[i][j];
		}
	}
	printf("%d", result);
	return 0;
}