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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    while (true) {
        sort(a, a+n);

        int g = a[1];
        for (int i = 1; i < n; i++) g = gcd(g, a[i]);

        ans = max(ans, g);
        if (a[0] == a[n-1]) break;

        for (int i = 0; i < n; i++) a[i] = gcd(a[0], a[i]);
    }

    cout << ans << "\n";
    return 0;
}