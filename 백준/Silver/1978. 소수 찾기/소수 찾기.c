#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int isPrime(int num)
{
	for (int i = 2; i < num; i++)
		if (num % i == 0)
			return 0;

	return 1;
}

int main(void)
{
	int* N;
	int n, count = 0;

	scanf("%d", &n);
	N = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) 
		scanf("%d", &N[i]);

	for (int i = 0; i < n; i++) {
		if (N[i] >= 2) {
			if (isPrime(N[i]))
				count++;
		}
	}
	printf("%d\n", count);
}