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

		cout << "preliminary check done" << '\n'; //for debug, good up until here

		while (!done) {
			cout << "Station: " << pos << "   Time: " << timer << '\n';
			cout << "Carrier top box: " << carrier.top() << '\n';
			
			while ((carrier.top() == pos) && !carrier.empty()) { //unloading cargo to platform A
				cout << "Unloading to A..." << '\n';
				carrier.pop();
				timer++;
			}
			cout << "Done unloading to platform A" << '\n';

			while (!carrier.empty() && (stations[pos].size() < q)) { //unloading rest to platform B
				cout << "Unloading to B..." << '\n';
				stations[pos].push(carrier.top());
				carrier.pop();
				timer++;
			}
			cout << "Done unloading to platform B" << '\n';

			while (carrier.size() < s) { //loading up the carrier until it's full
				carrier.push(stations[pos].front());
				stations[pos].pop();
				timer++;
			}


			done = true; //check if all stations and carrier are empty. If so, we are done.
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

			pos++; //If it made it this far, we have to go to the next station
			pos %= n; //using this to loop around once we reach the last one
			timer += 2; //It takes 2 minutes to go from one station to the next
		}

		cout << timer << '\n';

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
