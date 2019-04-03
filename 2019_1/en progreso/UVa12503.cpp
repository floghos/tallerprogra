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
            string temp;
            cin >> temp;
            switch (string(temp)) { //switch can only evaluate integers :/
                case "LEFT":
                    dir.push_back(left);
                case "RIGHT":
                    dir.push_back(right);
                case "SAME":
                    int num;
                    cin >> temp >> num;
                    dir.push_back(num - 1);
            }
        }

        for (int j = 0; j < n; j++){ // for testing
            cout << dir[j] << endl;
        }

    }
    return 0;
}
