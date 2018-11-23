#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int testCases;
	cin >> testCases;

	int output[testCases][2];
	for (int i = 0; i < testCases; ++i) {
		int streets, avenues, friends;
		scanf("%d %d %d", &streets, &avenues, &friends);

		int houses[friends][2];
		for (int j = 0; j < friends; ++j) {
			scanf("%d %d", &houses[j][0], &houses[j][1]);
		}

		int sumSt = 0;
		int sumAv = 0;

		for (int j = 0; j < friends; ++j) {
			sumSt += houses[j][0];
			sumAv += houses[j][1];
		}
		sumSt /= friends;
		sumAv /= friends;

		output[i][0] = sumSt;
		output[i][1] = sumAv;
	}

	for (int i = 0; i < testCases; ++i) {
		printf("(Street: %d, Avenue: %d)\n", output[i][0], output[i][1]);
	}
	printf("%d %d\n", sumSt, sumAv);

	return 0;
}
