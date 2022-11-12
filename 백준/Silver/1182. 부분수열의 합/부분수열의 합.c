#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, S;
int count = 0;
void pick(int* item, int index, int sum)
{
	int result;

	if (index != 0 && sum == S)
		count++;

	for (int i = index; i < N; i++) {
		result = sum + item[i];
		pick(item, i + 1, result);
	}
}


int main(void)
{
	int* item;

	scanf("%d %d", &N, &S);

	item = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &item[i]);

	pick(item, 0, 0);
	printf("%d\n", count);
}