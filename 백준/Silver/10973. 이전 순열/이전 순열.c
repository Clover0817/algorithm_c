#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* arr, int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

bool nextPermutation(int* arr, int len) {
	int i = len - 1;
	int j = len - 1;

	while (i > 0 && arr[i - 1] <= arr[i])
		i--;
	if (i <= 0)
		return false;

	while (arr[j] >= arr[i - 1])
		j--;

	swap(arr, i - 1, j);

	j = len - 1;
	while (i < j) {
		swap(arr, i, j);
		i++;
		j--;
	}

	return true;
}

int main(void)
{
	int* arr;
	int len;

	scanf("%d", &len);
	arr = (int*)malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++)
		scanf("%d", &arr[i]);

	if (nextPermutation(arr, len)) {
		for (int i = 0; i < len; i++)
			printf("%d ", arr[i]);
	}
	else
		printf("-1");
	printf("\n");
}