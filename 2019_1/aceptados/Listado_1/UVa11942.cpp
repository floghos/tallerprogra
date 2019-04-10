 #include <bits/stdc++.h>

 using namespace std;

 int main(int argc, char const *argv[]) {
 	int n;
	int last;
	int order; // creciente = 1;  decreciente = -1; determinando = 0; desordenado = -2;

	cin >> n;
	cout << "Lumberjacks:\n";
	for (int i = 0; i < n; i++) {
		cin >> last;
		order = 0;
		for (int j = 1; j < 10; j++) {
			int temp;
			cin >> temp;

			if (order == 0) {
				if (temp > last) order = 1;
				if (temp < last) order = -1;
			}
			if (order == 1) {
				if (!(temp >= last)) {
					order = -2;
					cout << "Unordered\n";
				}
			}
			if (order == -1) {
				if (!(temp <= last)) {
					order = -2;
					cout << "Unordered\n";
				}
			}
			last = temp;
			if (j == 9 && order != -2) {
				cout << "Ordered\n";
			}
		}
	}
 	return 0;
 }
