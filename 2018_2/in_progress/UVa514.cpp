#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	int n, aux, first, i, j;
	int coach, incoming;
	stack<int> station;
	vector<int> order;
	vector<string> results;

	cin >> n;
	while (n > 0) {
		cin >> first;
		while (first > 0) {
			order.push_back(first);
			for (i = 0; i < n-1; i++) {
				cin >> coach;
				order.push_back(coach);
			}
			incoming = 1;
			for (i = 0; i < n; i++) {
				if (order[i] == incoming) {
					incoming++;
				} else if (order[i] > incoming) {
					for(j = 0; j < order[i]-incoming; j++) {
						station.push(incoming);
						incoming++;
					}
				} else {
					if (station.top() == order[i]) {
						station.pop();
					} else {
						results.push_back("No");
						goto FinishTrain;
					}
				}
			}
			results.push_back("Yes");

			FinishTrain:
			order.clear();
			cin >> first;
		}
		results.push_back("");
		cin >> n;
	}

	for (i = 0; i < results.size(); i++) {
		cout << results[i] << endl;
	}
	return 0;
}
