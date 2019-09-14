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

class KMP {
    string pattern;
    vector <int> fail;

    void initKMP(const string &p) {
        pattern = p;
        int m = pattern.size();
        fail.assign(m + 1, -1);
        for (int i = 0, j = -1; i < m; i++) {
            while (j >= 0 && pattern[i] != pattern[j]) j = fail[j];
            j++;
            if (pattern[i + 1] == pattern[j]) fail[i + 1] = fail[j];
            else fail[i + 1] = j;
        }
    }

public:
    KMP(const string &p) { initKMP(p); }

    int period(int i) { return i - fail[i]; }

    vector <int> match(const string &s) {
        int n = s.size();
        int m = pattern.size();
        vector <int> res;
        for (int i = 0, k = 0; i < n; i++) {
            while (k >= 0 && s[i] != pattern[k]) k = fail[k];
            k++;
            if (k == m) res.push_back(i - m + 1);
        }
        return res;
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string S, T;
    cin >> S >> T;

    int n = S.size();
    int sn = S.size();
    int tn = T.size();

    while (sn < tn) {
        S += S;
        sn *= 2;
    }

    S += S;
    S += S;
    sn *= 4;

    KMP kmp(T);
    vector <int> vec = kmp.match(S);

    int mx = 0;
    vector <int> dp(sn + 1, 0);
    for (int idx : vec) {
        dp[idx + tn] = max(dp[idx + tn], dp[idx] + tn);
        mx = max(mx, dp[idx + tn]);
    }

    if (mx < origin * 2) {
        cout << mx / tn << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}