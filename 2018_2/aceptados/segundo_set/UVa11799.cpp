#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	int n, i, speed, max;
	char temp;
	cin >> n;
	int results[n];
	for (i = 0; i < n; i++) {
		max = 0;
		do {
			scanf("%d%c", &speed, &temp);
			if (speed > max) {
				max = speed;
			}
		} while(temp != '\n');
		results[i] = max;
	}
	for (i = 0; i < n; i++) {
		cout << "Case " << i+1 << ": " << results[i] << endl;
	}
	return 0;
}
