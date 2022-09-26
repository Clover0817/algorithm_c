#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//시간초과 주의(시간제한이 0.5초이므로 O(N) or O(NlogN)으로 풀어야=이중for문 불가)

int main()
{
	int n;
	long long gn = 0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		gn += (n / i) * i;
	}

	printf("%lld\n", gn);

	return 0;
}