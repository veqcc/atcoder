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

    ll n, k;
    cin >> n >> k;

    vector<int> A(n);
    map<int, bool> mp2;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (!mp2[A[i]]) {
            mp2[A[i]] = true;
            mp[A[i]] = i;
        }
    }

    vector<int> nxt(n); // 次に同じ文字が現れる最初のindex
    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = mp[A[i]];
        mp[A[i]] = i;
    }

    ll count = 1;
    int idx = 0;
    while (true) {
        if (nxt[idx] <= idx) count++;
        idx = (nxt[idx] + 1) % n;
        if (idx == 0) break;
    }

    k = (k + count - 1) % count;
    if (k == count - 1) return 0;

    idx = 0;
    while (true) {
        if (k <= 0) break;
        if (nxt[idx] <= idx) k--;
        idx = (nxt[idx] + 1) % n;
    }

    while (true) {
        if (idx >= n) break;
        if (nxt[idx] <= idx) {
            cout << A[idx] << " ";
            idx++;
        } else {
            idx = nxt[idx] + 1;
        }
    }

    return 0;
}