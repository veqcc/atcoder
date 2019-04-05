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

ll Q, A, B;

// [B,A)と(B,A)でAB未満のペアをk個作ることができるか
bool check(ll k) {
    // 最適にペアを作ったとき、k/2番目が最大になる
    ll idx = k / 2;
    if ((B + idx) * (B + k - idx) < A * B) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        cin >> A >> B;
        if (A < B) swap(A, B);

        ll l = 0, r = A - B;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }

        cout << 2 * (B - 1) + l << "\n";
    }

    return 0;
}