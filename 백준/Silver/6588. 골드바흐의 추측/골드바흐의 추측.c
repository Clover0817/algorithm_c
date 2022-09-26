#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
#include <stdio.h>

int n[100000];
int prime[MAX];

main(void)
{
	int i, size = 0;
	int a, b , ok = 0;

	for (int i = 0; i < MAX; i++)
		prime[i] = i;

	for (int i = 2; i < MAX; i++) {//에라토스테네스의 체 거르는 과정
		if (prime[i] == 0)
			continue;
		if (i * i > MAX)
			break;

		for (int j = 2; i * j < MAX; j++)
			prime[i * j] = 0;
	}

	scanf("%d", &n[0]);

	i = 1;
	while (n[i - 1] != 0) {//입력
		scanf("%d", &n[i]);
		i++;
		size++;
	}

	for (i = 0; i < size; i++) {//a, b가 소수인지 확인해 출력
		a = 3;
		b = n[i] - a;
		while (a <= b) {
			if (prime[a] == a) {
				if (prime[b] == b) {
					printf("%d = %d + %d\n", n[i], a, b);
					ok = 1;
					break;
				}
			}
			a += 2;
			b = n[i] - a;
		}
	}
	if (ok == 0)
		printf("Goldbach's conjecture is wrong.\n");

	return 0;
}