#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int testCases;
	cin >> testCases;

	int output[testCases];

	for (int i = 0; i < testCases; ++i) {
		int count = 0;

		int fieldSize;
		scanf("%d", &fieldSize);
		char field[fieldSize];

		char trashNewLine;
		scanf("%c", &trashNewLine);

		for (int j = 0; j < fieldSize; ++j) {
			scanf("%c", &field[j]);
		}
		scanf("%c", &trashNewLine);

		for (int j = 0; j < fieldSize; ++j) {
			if (j <= fieldSize - 3) {
				if (field[j] == '.') {
					field[j] = 's';
					field[j + 1] = 's';
					field[j + 2] = 's';
					count++;
				}
			} else if (j == fieldSize - 2) {
				if (field[j] == '.') {
					field[j] = 's';
					field[j + 1] = 's';
					count++;
				}
			} else if (j == fieldSize - 1) {
				if (field[j] == '.') {
					field[j] = 's';
					count++;
				}
			}
		}
		output[i] = count;
	}

	for (int i = 0; i < testCases; ++i) {
		cout << "Case " << i + 1 << ": " << output[i] << endl;
	}

	return 0;
}
