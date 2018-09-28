#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int cases, i, j, k;
	int aux;
	vector<int> cookies;
	vector<int> remaining;
	vector<int> posResult;

	cin >> cases;

	for (i = 0; i < cases; i++) {
		cin >> aux;
		cookies.push_back(aux);
		cin >> aux;
		remaining.push_back(aux);
	}

	int eaten;
	for (i = 0; i < cases; i++) {
		eaten = cookies[i] - remaining[i];
		if (eaten == 0) {
			cout << "Case #" << i + 1 << ": " << "0" << '\n';
		} else {
			for (j = 1; j < (int)sqrt(eaten) + 1; j++) {
				if ((eaten % j) == 0) {
					posResult.push_back(j);
				}
			}
			if (posResult.size() != 0) {
				for (k = posResult.size() - 1; k > -1; k--) {
					if (((float)posResult[k]) == sqrt(eaten)) {
						continue;
					}
					posResult.push_back((int)(eaten / posResult[k]));
				}
				cout << "Case #" << i + 1 << ":";
				for (k = 0; k < posResult.size(); k++) {
					if (posResult[k] <= remaining[i]) {
						continue;
					}
					cout << " " << posResult[k];
				}
				cout << '\n';
			} else {
				cout << "Case #" << i + 1 << ":" << '\n';
			}
		}
		posResult.clear();
	}
	return 0;
}
