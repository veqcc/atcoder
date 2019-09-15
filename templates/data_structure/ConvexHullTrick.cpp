#include <iostream>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;

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


// verified
//  https://atcoder.jp/contests/colopl2018-final/tasks/colopl2018_final_c
void AtCoder_2018_1_20_C() {
    ll N, a;
    cin >> N;
    ConvexHullTrick<ll> CHT(true);
    for (ll i = 0; i < N; i++) {
        cin >> a;
        CHT.add(-2 * i, a + i * i);
    }
    for (ll i = 0; i < N; i++) cout << CHT.get(i) + i * i << '\n';
}


// verified
//  https://yukicoder.me/problems/no/409
void yuki409() {
    ll n, a, b, w;
    cin >> n >> a >> b >> w;
    vector <ll> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    ConvexHullTrick<ll> CHT(true);
    vector <ll> dp(n + 1); // i日目に食べた時の体重の最大の変化量
    CHT.add(0, 0);
    for (ll i = 1; i <= n; i++) {
        dp[i] = CHT.get(i - 1) - a * (i - 1) + b * i * (i - 1) / 2 + d[i - 1];
        CHT.add(-i * b, dp[i] + a * i + b * i * (i - 1) / 2);
    }
    ll ans = dp[n];
    for (ll i = 0; i < n; i++) {
        ans = min(ans, dp[i] - a * (n - i) + b * (n - i) * (n - i + 1) / 2);
    }
    cout << ans + w << '\n';
}


int main() {
    // AtCoder_2018_1_20_C();
    yuki409();
    return 0;
}