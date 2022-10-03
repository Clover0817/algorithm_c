#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int getIntLen(int num)
{
    return floor(log10(num) + 1);
}

int main(void)
{
    int n, num, len;
    int m = 1, sum = 0;

    scanf("%d", &n);
    len = getIntLen(n);

    num = n;
    if (len == 1)
        printf("%d", n);
    else {
        for (int i = 1; i < len; i++) {
            sum += 9 * m * i;
            num -= 9 * m;
            m *= 10;
        }
        sum += len * num;
        printf("%d\n", sum);
    }
}