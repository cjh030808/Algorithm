#include <stdio.h>

int lower_bound(int *lis, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (lis[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], lis[n], idxAtPos[n], prev[n];
    int length = 0;

    for (int i = 0; i < n; i++) prev[i] = -1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        int pos = lower_bound(lis, length, arr[i]);
        lis[pos] = arr[i];   
        idxAtPos[pos] = i;

        if (pos > 0) prev[i] = idxAtPos[pos - 1];
        if (pos == length) length++;
    }
    printf("%d\n", length);
    
    int result[length];
    int cur = idxAtPos[length - 1];
    for (int i = length - 1; i >= 0; i--) {
        result[i] = arr[cur];
        cur = prev[cur];
    }

    for (int i = 0; i < length; i++) printf("%d ", result[i]);
    return 0;
}
