#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define MAX(a,b) a<b?b:a
#define MIN(a,b) a<b?a:b
#define SIZE 20

int score[SIZE][SIZE];
int visited[SIZE];
int N, half;
int team1[SIZE];
int team2[SIZE];
int min = 9999999;
void start_link() {
	int score1 = 0;
	int score2 = 0;

	for (int i = 0; i < half; i++) {
		for (int k = 1; k <= N; k++) {
			if (team1[i] != k && visited[k]) 
				score1 += score[team1[i] - 1][k - 1];
			if (team2[i] != k && !visited[k]) 
				score2 += score[team2[i] - 1][k - 1];
			
		}
	}
	min = MIN(min, abs(score1 - score2));
}

void check(int x, int start) {
	if (x == half) {
		int j = 0;
		for (int i = 1; i <= N; i++) {
			if (visited[i]) continue;
			team2[j++] = i;
		}
		start_link();
		return;
	}

	for (int i = start; i <= N; i++) {
		if (!visited[i]) {
			team1[x] = i;
			visited[i] = 1;
			check(x + 1, i + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &N);

	half = N / 2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &score[i][j]);

	check(0, 1);
	printf("%d\n", min);
	return 0;
}