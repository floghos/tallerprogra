#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	vector<int> diffSecuence;
	int n;
	vector<string> output;
	while (scanf("%d", &n) != EOF) {
		int last, current;
		bool jolly = true;
		cin >> last;
		if (n == 1) {
			//cout << "Jolly" << endl;
			output.push_back("Jolly");
		} else {
			for (int i = 0; i < n - 1; ++i) {
				cin >> current;
				diffSecuence.push_back(abs(last-current));
				last = current;
			}
			sort(diffSecuence.begin(), diffSecuence.end());

			for (int i = 0; i < n - 1; ++i) {
				if (diffSecuence[i] != i + 1) {
					//cout << "Not jolly" << endl;
					output.push_back("Not jolly");
					jolly = false;
					break;
				}
			}
			if (jolly) {
				//cout << "Jolly" << endl;
				output.push_back("Jolly");
			}

		}
		diffSecuence.clear();
	}

	for (int i = 0; i < output.size(); ++i) {
		cout << output[i] << endl;
	}
	return 0;
}
