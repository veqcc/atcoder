#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int LIS(vector <int> vec, bool is_strong = true) {
    const int INF = 1 << 30;
    int n = vec.size();
    vector <int> dp(n, INF);
    for (int i = 0; i < n; i++) {
        if (is_strong) *lower_bound(dp.begin(), dp.end(), vec[i]) = vec[i];
        else *upper_bound(dp.begin(), dp.end(), vec[i]) = vec[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp
void AOJ_DPL_1_D() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << LIS(a) << '\n';
}


// verified
//   https://abc006.contest.atcoder.jp/tasks/abc006_4
void AtCoder_2014_4_5_D() {
    int n;
    cin >> n;
    vector <int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    cout << n - LIS(c) << "\n";
    return 0;
}


// verified
//   https://abc038.contest.atcoder.jp/tasks/abc038_d
void AtCoder_2016_5_28_D() {
    int n, w, h;
    cin >> n;
    vector <P> wh(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> w >> h;
        wh[i] = {w, h};
    }
    sort(wh.begin(), wh.end(), [&](const P &a, const P &b) {
        if (a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    });
    for (int i = 0; i < n; i++) h[i] = wh[i].second;
    cout << LIS(h) << "\n";
}

int main() {
    // AOJ_DPL_1_D();
    // AtCoder_2014_4_5_D();
    AtCoder_2016_5_28_D()
    return 0;
}