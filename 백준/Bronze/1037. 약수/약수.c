#include <stdio.h>
#include <stdlib.h>
//정렬 필요, compare&qsort함수 사용
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
	int a, n;
	int* divisor;

	scanf("%d", &a);
	divisor = (int*)malloc(sizeof(int) * a);
	for (int i = 0; i < a; i++)
		scanf("%d", &divisor[i]);

	qsort(divisor, a, sizeof(int), compare);
	if (a % 2 == 0)
		n = divisor[a / 2 - 1] * divisor[a / 2];
	else
		n = divisor[a / 2] * divisor[a / 2];
	printf("%d\n", n);
}