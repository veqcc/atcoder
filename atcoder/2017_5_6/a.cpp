#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    if (a % 2 == 0 && a == b && b == c) {
        cout << -1 << "\n";
        return 0;
    }

    int ans = 0;
    while (true) {
        if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) break;
        int A = (b + c) / 2;
        int B = (a + c) / 2;
        int C = (a + b) / 2;
        a = A; b = B; c = C;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}