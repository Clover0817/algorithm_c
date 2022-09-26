#include <stdio.h>

int is_only1(int n)
{
	long long int multiple = 1;
	int count = 1;

	while (multiple % n != 0) {
		multiple = (multiple % n) * 10 + 1;  
		count++;
	}

	return count;
}

int main(void)
{
	int n;

	while (~scanf("%d", &n))
		printf("%d\n", is_only1(n));
}