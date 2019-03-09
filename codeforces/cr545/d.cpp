#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

vector <int> ZAlgorithm(const string& S) {
    int sz = S.size();
    vector <int> ret(sz);
    ret[0] = sz;

    int i = 1, j = 0;
    int mx = 0, mx_idx = 0;
    while (i < sz) {
        while (i+j < sz && S[j] == S[i+j]) j++;
        ret[i] = j;
        if (j == 0) { i++; continue; }
        int k = 1;
        while (i+k < sz && k+ret[k] < j) ret[i+k] = ret[k], k++;
        i += k; j -= k;
    }

    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;

    int s1=0, s0=0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') s1++;
        if (s[i] == '0') s0++;
    }

    int sz = t.size();
    vector <int> lcp = ZAlgorithm(t);
    int x = 1;
    for (; x < sz; x++) {
        if (lcp[x] == sz - x) break;
    }

    string T1 = "", T2 = "";
    int uni1 = 0, uni0 = 0;
    for (int i = 0; i < sz - x; i++) {
        if (t[i] == '1') uni1++;
        if (t[i] == '0') uni0++;
        T1 += t[i];
    }

    int t1 = 0, t0 = 0;
    for (int i = sz - x; i < sz; i++) {
        if (t[i] == '1') t1++;
        if (t[i] == '0') t0++;
        T2 += t[i];
    }

    int cnt = 1 << 30;
    if (t1) cnt = max(0, (s1 - uni1) / t1);
    if (t0) cnt = min(cnt, max(0, (s0 - uni0) / t0));

    string ret;
    if (cnt) {
        ret = T1;
        for (int i = 0; i < cnt; i++) ret += T2;
        for (int i = 0; i < s1 - uni1 - cnt * t1; i++) ret += '1';
        for (int i = 0; i < s0 - uni0 - cnt * t0; i++) ret += '0';
    } else {
        ret = s;
    }

    cout << ret << "\n";
    return 0;
}