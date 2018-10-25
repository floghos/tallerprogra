#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int lower, int upper, int target) {
	if (upper >= lower) {
		int mid = lower + (upper - lower)/2;

		if (arr[mid] == target) {
			return mid;
		}
		if (arr[mid] < target){
			return binarySearch(arr, mid+1, upper, target);
		}
		return binarySearch(arr, lower, mid-1, target);
	}
	return upper;
}



int main(int argc, char const *argv[]) {
	int l, q, temp;

	cin >> l;
	int ladies[l];
	for (int i = 0; i < l; ++i) {
		cin >> ladies[i];
	}

	cin >> q;
	int queries[q];
	for (int i = 0; i < q; ++i) {
		cin >> queries[i];
	}

	for (int i = 0; i < q; ++i) {
		int find = binarySearch(ladies, 0, l-1, queries[i]);
		if (find < 0) {
			int taller = 0;
			while (ladies[taller] == queries[i]) {
				taller++;
			}
			if (taller < l) {
				cout << "X " << ladies[taller] << endl;
			} else {
				cout << "X X" << endl;
			}

		} else {
			int smaller = find;
			int taller = find;
			while (ladies[taller] <= queries[i]) {
				taller++;
			}
			while (ladies[smaller] >= queries[i]) {
				smaller--;
			}

			if (smaller >= 0) {
				if (taller < l) {
					cout << ladies[smaller] << " " << ladies[taller] << endl;
				} else {
					cout << ladies[smaller] << " X" << endl;
				}
			} else {
				if (taller < l) {
					cout << "X " << ladies[taller] << endl;
				} else {
					cout << "X X" << endl;
				}
			}
		}
	}

	return 0;
}
