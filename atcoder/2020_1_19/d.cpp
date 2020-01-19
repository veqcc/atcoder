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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> N;
    for (int i = 1000000; i; i /= 10) {
        if (n / i) {
            N.push_back(n / i % 10);
        }
    }

    int sz = N.size();
    if (sz == 1) {
        cout << n << '\n';
        return 0;
    }

    ll ans = 0;
    for (int a = 1; a <= n; a++) {
        int head;
        for (int i = 1000000; i; i /= 10) {
            if (a / i) {
                head = a / i;
                break;
            }
        }

        int tail = a % 10;

        if (tail == 0) continue;
        if (head == tail) ans++;

        int tmp = 1;
        for (int i = 1; i < sz - 1; i++) {
            ans += tmp;
            tmp *= 10;
        }

        if (N[0] > tail) {
            ans += tmp;
        } else if (N[0] == tail) {
            int n_sub = 0;
            for (int i = 1; i < sz; i++) {
                n_sub *= 10;
                n_sub += N[i];
            }

            ans += (n_sub - head + 10) / 10;
        }
    }

    cout << ans << "\n";
    return 0;
}