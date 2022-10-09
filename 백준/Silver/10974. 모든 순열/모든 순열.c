#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int* bucket, int bucketSize, int k)  //순열
{
	int i, lastIndex, smallest, item, chosen;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	smallest = 0;

	for (item = smallest; item < n; item++) {
		chosen = 0;
		for (i = 0; i < lastIndex + 1; i++) {
			if (bucket[i] == item + 1) {
				chosen = 1;
				break;
			}
		}

		if (chosen == 0) {
			bucket[lastIndex + 1] = item + 1;
			pick(n, bucket, bucketSize, k - 1);
		}
	}
}
int main(void)
{
	int* bucket;
	int n;
	
	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);
	pick(n, bucket, n, n);
}