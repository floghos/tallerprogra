#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int cases;
	cin >> cases;

	for (int i = 0; i < cases; i++) {
		int l, m; //l: ferry length, m: number of cars
		int counter = 0; //counter: number of times crossing the river
		int s = -1;// s: side of the river the ferry is currently in // -1 = left // 1 = right.
		queue<int> leftQ, rightQ;

		cin >> l >> m;
		l *= 100; //transforming from meters to centimeters

		for (int j = 0; j < m; j++) {
			int carLen;
			char side;
			string trash;
			cin >> carLen >> side >> trash;
			if (side == 'l') {
				leftQ.push(carLen);
			} else {
				rightQ.push(carLen);
			}
		}

		while (!leftQ.empty() || !rightQ.empty()) {
			int usedSpace = 0; //used ferry space
			if (s < 0) { // if we are on the left side
				if (!leftQ.empty()) {
					do {
						usedSpace += leftQ.front();
						leftQ.pop();
					} while(!leftQ.empty() && ((usedSpace+leftQ.front()) <= l) );
				}
				s *= -1;
				counter++;
			} else { //else we are on the right side
				if (!rightQ.empty()) {
					do {
						usedSpace += rightQ.front();
						rightQ.pop();
					} while(!rightQ.empty() && ((usedSpace+rightQ.front()) <= l));
				}
				s *= -1;
				counter++;
			}
		}
		cout << counter << '\n';

	}

	return 0;
}
