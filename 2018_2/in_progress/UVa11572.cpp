#include <bits/stdc++.h>

using namespace std;

int customBinarySearch(vector<int> arr, int lower, int upper, int target) {
	//if not found, returns the closest number that is lower than the target
	if (upper >= lower) {
		int mid = lower + (upper - lower)/2;

		if (arr[mid] == target) {
			return mid;
		}
		if (arr[mid] < target){
			return customBinarySearch(arr, mid+1, upper, target);
		}
		return customBinarySearch(arr, lower, mid-1, target);
	}
	return upper;
}

int main(int argc, char const *argv[]) {
	int cases;
	vector<int> output;
	vector<int> sflakes;
	//vector<int> bag;
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
				repeat = customBinarySearch(sflakes, begin, end, sflakes[j]);
				end = j; //set the new ending index
				if (repeat < 0 || sflakes[repeat] != sflakes[j]) { //if sflakes[j] was not found between begin and end
					if ((end-begin+1) > maxBag) {
						maxBag = end - begin + 1;
					}
				} else if (sflakes[repeat] == sflakes[j]) {
					begin = repeat + 1; //set the new starting index
					// end = j; //set the new ending index
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
