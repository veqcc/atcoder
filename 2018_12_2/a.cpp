#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    bool ans = false;
    if (n == 3 || n == 5 || n == 7) ans = true;

    if (ans) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}