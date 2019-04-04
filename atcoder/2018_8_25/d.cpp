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

int mx, a[100005];
ll n, bit[100005];

// iが与えられた時に、a[1]+a[2]+...+a[i]を計算する
ll sum(int i) {
    ll s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i; // 最後の1ビット
    }
    return s;
}

// iとxが与えられた時に、a[i]に1を足す
void add(int i) {
    while (i <= mx) {
        bit[i]++;
        i += i & -i;
    }
}

// Mediansのうち、k以上のものが n(n+1)/4 個以上あるかどうか
bool check(int k) {
    vector <int> b(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (a[i] >= k) b[i] = 1;
        else b[i] = -1;
    }

    int mn = 0;
    for (int i = 1; i <= n; i++) {
        b[i] += b[i-1];
        mn = min(mn, b[i]);
    }

    mx = 0;
    for (int i = 0; i <= n; i++) {
        b[i] += 1 - mn;
        mx = max(mx, b[i]);
    }

    ll inv = 0;
    fill(bit, bit+100005, 0);
    for (int i = 0; i <= n; i++) {
        inv += sum(b[i]);
        add(b[i]);
    }

    if (inv >= n * (n + 1) / 2 - n * (n + 1) / 4) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n == 1) {
        cout << a[1] << "\n";
        return 0;
    }

    int l = 0, r = 1e9+1;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << "\n";
    return 0;
}