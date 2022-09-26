#include <stdio.h>

#define MAX 1000000

int main()
{
    int T, N;
    long long sum[MAX + 1] = {0};

    for(int i = 1; i <= MAX; i++){ 
        for(int j = 1; i * j <= MAX; j++){
            sum[i * j] += i;
        }
        sum[i] += sum[i - 1]; 
    }
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);

        printf("%lld\n", sum[N]);
    }
}