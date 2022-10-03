#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int itemSize, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest;
	int sum = 0;
	int lastSelect; //중복 막아주는 변수

	if (k == 0) {
		for (int i = 0; i < (bucketSize - k); i++)
			sum += items[bucket[i]];

		if (sum > 100)
			return;
		if (sum == 100) {
			for (i = 0; i < (bucketSize - k); i++)
				printf("%d\n", items[bucket[i]]);
			exit(0);
		}
	}
	else {
		lastIndex = bucketSize - k - 1;

		if (bucketSize == k)
			smallest = 0;
		else
			smallest = bucket[lastIndex] + 1;

		lastSelect = -1; //중복을 막는, 절대 나오지 않을 값
		for (i = smallest; i < itemSize; i++) {
			if (lastSelect != items[i]) {
				lastSelect = items[i];

				bucket[lastIndex + 1] = i;
				pick(items, itemSize, bucket, bucketSize, k - 1);
			}
		}
	}
}


int static compare(const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main(void)
{
    int list[9];
	int bucket[7];

	for (int i = 0; i < 9; i++)
        scanf("%d", &list[i]);
    
   qsort(list, 9, sizeof(int), compare);
   pick(list, 9, bucket, 7, 7);
}