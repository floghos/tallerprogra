#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, temp, sum, cost;
	vector<int> v;
	vector<int> output;

	cin >> n;
	while(n != 0) {
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());

		cost = 0;
		for (int i = 0; i < n - 1; ++i) {
			sum = v[0] + v[1];
			cost += sum;

			v.erase(v.begin());
			v.erase(v.begin());

			auto it = v.begin();

			for (; it != v.end(); it++) {
				if (sum > *it) {
					continue;
				} else {
					break;
				}
			}
			if (it == v.end()) {
				v.push_back(sum);
			} else {
				v.insert(it, sum);
			}

		}
		output.push_back(cost);

		v.clear();
		cin >> n;
	}

	for (int i = 0; i < output.size(); ++i) {
		cout << output[i] << endl;
	}
	return 0;
}
