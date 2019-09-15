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

template<typename T>
class ConvexHullTrick {
private:
    typedef pair <T, T> P;
    vector <P> lines;
    bool isMonotonic;
    function<bool(T l, T r)> comp;
public:
    ConvexHullTrick(bool M = false, function<bool(T l, T r)> c = [](T l, T r) { return l >= r; })
            : isMonotonic(M), comp(c) {}
    bool check(P l1, P l2, P l3) {
        if (l1 < l3) swap(l1, l3);
        return (l3.second - l2.second) * (l2.first - l1.first) >= (l2.second - l1.second) * (l3.first - l2.first);
    }
    void add(T a, T b) {
        P line = P(a, b);
        while (lines.size() >= 2 && check(*(lines.end() - 2), lines.back(), line)) lines.pop_back();
        lines.push_back(line);
    }
    T f(int k, T x) { return lines[k].first * x + lines[k].second; }
    T f(P line, T x) { return line.first * x + line.second; }
    T get(T x) {
        if (isMonotonic) {
            static int head = 0;
            while (lines.size() - head >= 2 && comp(f(head, x), f(head + 1, x))) head++;
            return f(head, x);
        } else {
            int lb = -1, ub = lines.size() - 1;
            while (ub - lb > 1) {
                int md = (ub + lb) / 2;
                if (comp(f(md, x), f(md + 1, x))) lb = md;
                else ub = md;
            }
            return f(ub, x);
        }
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll N, a;
    cin >> N;

    ConvexHullTrick<ll> CHT(true);
    for (ll i = 0; i < N; i++) {
        cin >> a;
        CHT.add(-2 * i, a + i * i);
    }

    for (ll i = 0; i < N; i++) {
        cout << CHT.get(i) + i * i << '\n';
    }

    return 0;
}