#include <stdio.h>
int heap_size = 0;
typedef struct number {
	int num;
	int abs_num;
} number;

int abs(int x) {
	if (x < 0) x *= -1;
	return x;
}

void push(int x, number* num_set) {
	int cur = ++heap_size;
	while (cur != 1 && (
			num_set[cur / 2].abs_num > abs(x) || 
			(num_set[cur / 2].abs_num == abs(x) && num_set[cur / 2].num > x)
		)) {
		num_set[cur].num = num_set[cur / 2].num;
		num_set[cur].abs_num = num_set[cur / 2].abs_num;
		cur /= 2;
	}
	num_set[cur].num = x;
	num_set[cur].abs_num = abs(x);
}
int pop(number* num_set) {
    if (!heap_size) return 0; 

    int parent = 1, child = 2;
    int ret = num_set[1].num; 
    int tmp_num = num_set[heap_size].num;
    int tmp_abs = num_set[heap_size].abs_num;
    heap_size--;

    while (child <= heap_size) {
        if (child < heap_size && (
            num_set[child].abs_num > num_set[child + 1].abs_num ||
            (num_set[child].abs_num == num_set[child + 1].abs_num &&
                num_set[child].num > num_set[child + 1].num)
            )) {
            child++;
        }

        if (tmp_abs < num_set[child].abs_num ||
            (tmp_abs == num_set[child].abs_num && tmp_num <= num_set[child].num)) {
            break;
        }

        num_set[parent].num = num_set[child].num;
        num_set[parent].abs_num = num_set[child].abs_num;
        parent = child;
        child *= 2;
    }
    num_set[parent].num = tmp_num;
    num_set[parent].abs_num = tmp_abs;

    return ret;
}


int main() {
	int n, num;
	scanf("%d", &n);
	
	number num_set[n + 1];
	while(n--) {
		scanf("%d", &num);
		if (num) push(num, num_set);
		else printf("%d\n", pop(num_set));
	}
	return 0;
}