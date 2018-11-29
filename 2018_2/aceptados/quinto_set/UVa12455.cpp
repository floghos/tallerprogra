#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[]) {
	char output[50][4];
	int testCases;
	char mask = 1;
	vector<int> bars;
	int progress;

	cin >> testCases;

	for (int i = 0; i < testCases; ++i) {
		int goal;
		int numBars;

		cin >> goal;
		cin >> numBars;


		for (int j = 0; j < numBars; ++j) {
			int temp;
			cin >> temp;
			bars.push_back(temp);
		}

		if (!goal) {
			output[i][0] ='Y'; output[i][1] ='E'; output[i][2] ='S'; output[i][3] ='\0';
			continue;
		}

		int numCombis = 1 << numBars;
		for (int j = 0; j < numCombis; ++j) {
			progress = 0;
			for (int k = 0; k < numBars; ++k) {
				if (j & (mask << k)) {
					progress += bars[k];
				}
			}
			if (progress == goal) {
				output[i][0] ='Y'; output[i][1] ='E'; output[i][2] ='S'; output[i][3] ='\0';
				goto nextCase;
			}
		}
		output[i][0] ='N'; output[i][1] ='O'; output[i][2] ='\0';

		nextCase:
		bars.clear();
	}

	for (int i = 0; i < testCases; ++i) {
		cout << output[i] << endl;
	}

	return 0;
}
