#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	double base, debt;
	int months, n;

	cin >> months >> base >> debt >> n;

	while (months > 0) {

		vector<pair<int, double> > records;
		int cuota = debt / months;
		double carValue;

		for (int i = 0; i < n; ++i) {
			pair<int, double> temp;
			cin >> temp.first >> temp.second;
			records.push_back(temp);
		}
		carValue = debt + base;

		int k = 0;
		double devalRate;

		for (int i = 0; i < months; i++) {

			if (i == records[k].first) {
				devalRate = records[k].second;
				k++;
			}
			carValue -= carValue*devalRate;

			if (carValue > debt) {
				if (i == 1) {
					cout << "1 month" << "\n";
				} else {
					cout << i << " months" << "\n";
				}
				break;
			} else if (i == months - 1) {
				cout << i + 1 << " months" << "\n";
				break;
			}

			debt -= cuota;
		}
		cin >> months >> base >> debt >> n;
	}
	return 0;
}
