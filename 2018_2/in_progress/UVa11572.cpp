#include <bits/stdc++.h>

using namespace std;

int search(vector<int> arr, int begin, int end, int target) {
	for (int i = 0; i < (end-begin+1); ++i) {
		if (arr[begin + i] == target) return begin + i;
	}
	return -1;
}

int main(int argc, char const *argv[]) {
	int cases;
	vector<int> output;
	vector<int> sflakes;
	int maxBag;

	cin >> cases;
	for (int i = 0; i < cases; ++i) {
		int n;
		maxBag = 0;

		cin >> n;
		for (int j = 0; j < n; ++j) {
			int aux;
			cin >> aux;
			sflakes.push_back(aux);
		}

		int begin, end, repeat;
		begin = 0;
		end = 0;
		
		if (sflakes.size() == 1) {
			output.push_back(1);
		} else {
			for (int j = 1; j < sflakes.size(); ++j) {
				repeat = search(sflakes, begin, end, sflakes[j]);
				end = j; //set the new ending index
				if (repeat == -1) { //if sflakes[j] was not found between begin and end
					if ((end-begin+1) > maxBag) {
						maxBag = end - begin + 1;
					}
				} else { //if sflakes[j] was found
					begin = repeat + 1; //set the new starting index
					if ((end-begin+1) > maxBag) {
						maxBag = end - begin + 1;
					}
				}
			}
			output.push_back(maxBag);
		}

		sflakes.clear();
	}
	for (int i = 0; i < output.size(); ++i) {
		cout << output[i] << endl;
	}

	return 0;
}
