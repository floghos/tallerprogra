#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	vector<string> urls;
	string tempStr;
	int views;
	int top = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> tempStr >> views;

			if (views == top) {
				urls.push_back(tempStr);
			}

			if (views > top) {
				urls.clear();
				top = views;
				urls.push_back(tempStr);
			}

		}
		cout << "Case #" << i+1 << ":\n";
		for (int j = 0; j < urls.size(); j++) {
			cout << urls[j] << "\n";
		}

		top = 0;
		urls.clear();
	}

	return 0;
}
