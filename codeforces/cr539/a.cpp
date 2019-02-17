#include <algorithm>
#include <iostream>
#include <iomanip>
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
    cout.tie(0);

    int n, v;
    cin >> n >> v;

    if (n - 1 <= v) {
        cout << n-1 << "\n";
    } else {
        int ans = v;
        for (int i = 2; i <= n - v; i++) {
            ans += i;
        }
        cout << ans << "\n";
    }

    return 0;
}