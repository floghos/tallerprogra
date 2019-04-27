#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int sets;
	cin >> sets;

	for (int k = 0; k < sets; k++) {
		int n, s, q;
		cin >> n >> s >> q;

		vector< queue<int> > stations;
		stack <int> carrier;
		bool done; //flag used to see if the task has been finished
		int timer = 0; //"timer" will keep track of how long the process is taking
		int pos = 0; //"pos" refers to which station the carrier is currently in

		for (int i = 0; i < n; ++i) {
			queue<int> b;
			int numCargo;
			cin >> numCargo;
			for (int j = 0; j < numCargo; j++) {
				int temp;
				cin >> temp;
				b.push(temp);
			}
			stations.push_back(b);
		}

		done = true; //preliminary check
		if (carrier.empty()) {
			for (int i = 0; i < n; i++) {
				if (!stations[i].empty()) {
					done = false;
					break;
				}
			}
		} else {
			done = false;
		}

		while (!done) {
			while (carrier.top() == pos) { //unloading cargo to platform A
				carrier.pop();
				timer++;
			}
			while (!carrier.empty() && (stations[pos].size() < q)) { //unloading rest to platform B
				stations[pos].push_back(carrier.top());
				carrier.pop();
				timer++;
			}

			while (carrier.size() < s) { //loading up the carrier until it's full
				carrier.push(stations[pos].front());
				stations[pos].pop();
				timer++;
			}


			done = true;
			if (carrier.empty()) {
				for (int i = 0; i < n; i++) {
					if (!stations[i].empty()) {
						done = false;
						break;
					}
				}
			} else {
				done = false;
			}
			if (done) break;

			pos++;
			pos %= n;
			timer += 2;
		}

		// for (int i = 0; i < stations.size(); i++) { //checking input
		// 	int len = stations[i].size();
		// 	for (int j = 0; j < len; j++) {
		// 		cout << stations[i].front() << " ";
		// 		stations[i].pop();
		// 	}
		// 	cout << '\n';
		// }

	}
	return 0;
}
