#include <functional>
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

    int n, q;
    cin >> n >> q;

    vector <int> a(n), idx(1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) {
            int g = gcd(a[i], a[i - 1]);
            if (a[i - 1] != g) idx.push_back(i);
            a[i] = g;
        }
    }

    while (q--) {
        int s;
        cin >> s;

        bool one = false;
        for (int i : idx) {
            s = gcd(s, a[i]);
            if (s == 1) {
                cout << i + 1 << '\n';
                one = true;
                break;
            }
        }

        if (!one) {
            cout << s << '\n';
        }
    }

    return 0;
}