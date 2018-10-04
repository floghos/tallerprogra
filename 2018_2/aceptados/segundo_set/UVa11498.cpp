#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	int n, i;
	int dpointX, dpointY;
	int x, y;
	vector<string> results;
	cin >> n;
	while (n != 0) {
		cin >> dpointX;
		cin >> dpointY;
		for (i = 0; i < n; i++) {
			cin >> x;
			cin >> y;
			if ((x - dpointX) == 0 || (y - dpointY) == 0) {
				results.push_back("divisa"); //cout << "divisa" << endl;
			} else {
				if ((x - dpointX) < 0) {
					if ((y - dpointY) < 0) {
						results.push_back("SO"); //cout << "SO" << endl;
					} else {
						results.push_back("NO"); //cout << "NO" << endl;
					}
				} else {
					if ((y - dpointY) < 0) {
						results.push_back("SE"); //cout << "SE" << endl;
					} else {
						results.push_back("NE"); //cout << "NE" << endl;
					}
				}
			}
		}
		cin >> n;
	}
	for (i = 0; i < results.size(); i++) {
		cout << results[i] << endl;
	}

	return 0;
}
