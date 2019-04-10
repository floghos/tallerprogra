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
                case 'R':
                    dir.push_back(right);
                case 'S':
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
