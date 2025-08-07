#include <stdio.h>

int lower_bound(int arr[], int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N], LIS[N], length = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        int pos = lower_bound(LIS, length, arr[i]);
        LIS[pos] = arr[i];
        if (pos == length) length++;
    }
    printf("%d\n", length);
    return 0;
}