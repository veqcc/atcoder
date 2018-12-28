#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, z, w;
    cin >> n >> z >> w;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << abs(a[0] - w) << "\n";
    } else {
        cout << max(abs(a[n-1] - w), abs(a[n-1] - a[n-2])) << "\n";
    }

    return 0;
}