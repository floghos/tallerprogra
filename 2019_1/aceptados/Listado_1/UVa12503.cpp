#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int left = -1, right = -2;
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        vector<int> dir;
        cin >> n;
        for (int j = 0; j < n; j++) {
            char c;
            string temp;
            cin >> c >> temp;
			switch (c) {
                case 'L':
                    dir.push_back(left);
					break;
                case 'R':
                    dir.push_back(right);
					break;
                case 'S':
                    int num;
                    cin >> temp >> num;
                    dir.push_back(num - 1);
					break;
            }
        }

		int position = 0;
		for (int j = 0; j < n; j++) {
			int k = j;
			while (dir[k] >= 0) {
				k = dir[k];
			}
			if (dir[k] == left) position--;
			if (dir[k] == right) position++;
		}
		cout << position << "\n";
    }
    return 0;
}
