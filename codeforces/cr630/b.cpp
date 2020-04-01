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

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector <int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector <int> primes = {
                2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31
        };

        int ans = 0;
        vector <int> idx(n, -1);
        for (int j = 0; j < 11; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (idx[i] == -1 && a[i] % primes[j] == 0) {
                    cnt++;
                    idx[i] = ans;
                }
            }

            if (cnt) ans++;
        }

        cout << ans << '\n';
        for (int i : idx) {
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}