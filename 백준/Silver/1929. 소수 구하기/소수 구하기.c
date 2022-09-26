#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* num;
	int M, N;

	scanf("%d %d", &M, &N);
	num = (int*)malloc(sizeof(int) * (N + 1)) ;

	for (int i = 0; i <= N; i++)
		num[i] = i;

	if (M == 1) //1이면 소수가 아니므로 0
		num[M] = 0;

	for (int i = 2; i <= N; i++) {//2의 배수부터 지워나감
		if (num[i] == 0)
			continue;
		if (i * i > N)
			break;

		for (int j = 2; i * j <= N; j++)//prime은 남기고 prime*2부터 지워져야 함
			num[i * j] = 0;
	}
  
	for (int i = M; i <= N; i++) {
		if (num[i] != 0)
			printf("%d\n", i);
	}
}