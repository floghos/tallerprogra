#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, m;
	vector<int> heads;
	vector<int> knights;
	vector<int> output;

	cin >> n;
	cin >> m;

	while (!(n == 0 && m == 0)) {
		int temp;
		int cost = 0
		;
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			heads.push_back(temp);
		}
		for (int i = 0; i < m; ++i) {
			cin >> temp;
			knights.push_back(temp);
		}
		sort(heads.begin(), heads.end());
		sort(knights.begin(), knights.end());

		for (int i = 0; i < heads.size(); ++i) { //for each head
			if (knights.empty()) { //there are no knights left to defend the kingdom!!
				output.push_back(-1); //Loowater is doomed!!! T.T
				goto nextCase;//Oh well, onto the next test case...
			}
			int remainingKnights = knights.size();
			for (int j = 0; j < remainingKnights; ++j) { //we look for a knight tall enough for the job
				if (knights[0] >= heads[i]) {
					cost += knights[0]; //knight has chopped a head. He has to get paid
					knights.erase(knights.begin()); //knight has been paid and can HEAD OFF to see his family once more. :D
					break; //onto the next head!!
				} else {
					knights.erase(knights.begin()); //knight can't chop the smallest remining head so we chop HIS head instead!
				}
			}
		}
		output.push_back(cost);

		nextCase:
		//resetting for next test case
		heads.clear();
		knights.clear();
		cin >> n;
		cin >> m;
	}

	for (int i = 0; i < output.size(); ++i) { 
		if (output[i] != -1) {
			cout << output[i] << endl;
		} else {
			cout << "Loowater is doomed!" << endl;
		}
	}

	return 0;
}
