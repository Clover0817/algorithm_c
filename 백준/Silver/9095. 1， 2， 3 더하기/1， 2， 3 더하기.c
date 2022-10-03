#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count = 0;

void pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int n)
{
	int i, lastIndex, smallest = 0;
	int sum = 0;

	for (i = 0; i < (bucketSize - k); i++)
		sum += items[bucket[i]];

	if (sum > n)
		return;
	else if (sum == n)
		count++;
	else {
		lastIndex = bucketSize - k - 1;

		for (i = 0; i < itemSize; i++) {
			bucket[lastIndex + 1] = i;

			pick(items, itemSize, bucket, bucketSize, k - 1, n);
		}
	}
}

int main(void)
{
	int items[] = { 1, 2, 3 };
	int* bucket;
	int* n;
	int num;

	scanf("%d", &num);
	n = (int*)malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++)
		scanf("%d", &n[i]);
	for (int i = 0; i < num; i++) {
		bucket = (int*)malloc(sizeof(int) * n[i]);
		pick(items, 3, bucket, n[i], n[i], n[i]);
		printf("%d\n", count);
		count = 0;
		free(bucket);
	}
}