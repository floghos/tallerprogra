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

		for (int i = 0; i < n; ++i) { //for testing
			cout << v[i] << " ";	  //need to delete
		}							  //all of this.
		cout << endl; 				  //don't forget


		sum = v[0] + v[1];
		cost = sum;
		for (int i = 2; i < n; ++i) {
			sum += v[i];
			cost += sum;
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
