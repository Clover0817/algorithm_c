#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void dfs(int* item, int* bucket, int n, int start, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	for (int i = start; i < n; i++) {
		bucket[depth] = item[i];
		dfs(item, bucket, n, i + 1, depth + 1);
	}
}

int main() {
	int n;
	int* item;
	int bucket[6];

	while (1) {
		scanf("%d", &n);
		if (!n) break;
		item = (int*)malloc(sizeof(int) * n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &item[i]);
		}
		dfs(item, bucket, n, 0, 0);
		printf("\n");

		free(item);
	}

	return 0;
}
