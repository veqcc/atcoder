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

ll n, k;
ll A[100005], B[100005];

// 金額がiのコインはk番目未満か
bool check(ll i) {
    ll cnt = 0;
    for (int j = 0; j < n; j++) {
        if (i >= A[j]) {
            if (i <= B[j]) {
                cnt += i - A[j] + 1;
            } else {
                cnt += B[j] - A[j] + 1;
            }
        }
    }

    if (cnt < k) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        cin >> A[i] >> B[i];
    }

    ll l = 0, r = 1e9;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << r << "\n";
    return 0;
}