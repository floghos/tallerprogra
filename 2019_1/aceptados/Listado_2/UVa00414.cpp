#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	while (n > 0) {

		int rowLen[n] = {0};
		int maxLen = 0;
		for (int i = 0; i < n; i++) {
			char newLine;
			scanf("%c", &newLine);
			for (int j = 0; j < 25; j++) {
				char c;
				scanf("%c", &c);
				if (c == 'X') rowLen[i]++;
			}
			if (rowLen[i] > maxLen) maxLen = rowLen[i];
		}

		int totalVoid = 0;
		for (int i = 0; i < n; i++) {
			totalVoid += maxLen - rowLen[i];
		}
		cout << totalVoid << '\n';

		cin >> n;
	}
	return 0;
}
