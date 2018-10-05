#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	vector<vector<int> > combis;
	vector<int> auxVector;
	vector<int> frecuencies;

	int frosh;
	int i, j, k;
	int isSame;
	int auxInt;

	cin >> frosh;
	while (frosh != 0) {
		isSame = 0;
		for (i = 0; i < frosh; i++) {
			for (j = 0; j < 5; j++) {
				cin >> auxInt;
				auxVector.push_back(auxInt);
			}
			combis.push_back(auxVector);
			auxVector.clear();

			sort(combis.back().begin(), combis.back().end());

			for (k = 0; k < combis.size()-1; k++) {
				isSame = 0;

				if (combis[k] == combis.back()) {
					isSame = 1;
					frecuencies[k]++;
					combis.pop_back();
					break;
				}
			}
			if (isSame == 0) {
				frecuencies.push_back(1);
			}

		}

		sort(frecuencies.begin(), frecuencies.end());
		int top = frecuencies.back();
		int count = 0;
		for (i = frecuencies.size()-1; i >= 0; --i) {
			if(frecuencies[i] == top) {
				count += top;
			} else {
				break;
			}
		}
		cout << count << endl;

		frecuencies.clear();
		combis.clear();
		cin >> frosh;
	}
	return 0;
}
