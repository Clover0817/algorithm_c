#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isPrime(int num) 
{
	for (int i = 2; i < num; i++) 
		if (num % i == 0)
			return 0;
	
	return 1;
}
int main(void)
{
	int n1, n2, i;
	int maxD = 1, minM = 1;

	scanf("%d %d", &n1, &n2);

	i = 2;
	while (n1 >= i && n2 >= i) {
		if (n1 % i == 0 && n2 % i == 0) {
			n1 /= i;
			n2 /= i;
			maxD *= i;
			continue;
		}

		i++;
		while (!isPrime(i)) {
			i++;
		}
	}

	minM = maxD * n1 * n2;
	printf("%d\n%d\n", maxD, minM);
}