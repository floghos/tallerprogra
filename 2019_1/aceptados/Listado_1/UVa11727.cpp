#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]) {
  int t;
  int a, b, c;
  vector<int> arr;
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> a >> b >> c;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    sort(arr.begin(), arr.end());

    cout << "Case " << i + 1 << ": " << arr[1] << "\n";
    arr.clear();
  }

  return 0;
}
