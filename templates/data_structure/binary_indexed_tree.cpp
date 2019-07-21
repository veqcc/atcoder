#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

class BinaryIndexedTree {
    int N;
    vector <ll> bit;

public:
    BinaryIndexedTree(int N) : N(N), bit(N + 1, 0) {}

    void add(int k, ll w) {
        for (int x = k; x <= N; x += x & -x) bit[x] += w;
    }

    // sum of bit[0:k]
    ll sum(int k) {
        ll ret = 0;
        for (int x = k; x > 0; x -= x & -x) ret += bit[x];
        return ret;
    }
};


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
void AOJ_DSL_2_B() {
    int n, q, com, x, y;
    cin >> n >> q;
    BinaryIndexedTree bit(n);
    while (q--) {
        cin >> com >> x >> y;
        if (com == 0) bit.add(x, y);
        else cout << bit.sum(y) - bit.sum(x - 1) << '\n';
    }
}


// verified
//   https://arc033.contest.atcoder.jp/tasks/arc033_3
void AtCoder_2015_1_31_C() {
    int Q, T, X;
    cin >> Q;
    BinaryIndexedTree bit(200000);
    while (Q--) {
        cin >> T >> X;
        if (T == 1) bit.add(X, 1);
        else {
            int l = 0, r = 200000;
            while (l + 1 < r) {
                int med = (l + r) / 2;
                if (bit.sum(med) >= X) r = med;
                else l = med;
            }
            cout << r << '\n';
            bit.add(r, -1);
        }
    }
}

int main() {
    // AOJ_DSL_2_B();
    AtCoder_2015_1_31_C();
    return 0;
}