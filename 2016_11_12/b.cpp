#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int p[20005];
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        p[t] = i;
    }

    for (int i = 1; i <= n; i++) {
        cout << 30000 * i << " ";
    }
    cout << "\n";

    for (int i = 1; i <= n; i++) {
        cout << 30000 * (n - i + 1) + p[i] << " ";
    }

    return 0;
}