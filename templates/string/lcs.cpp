#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Longest Common Subsequence

class LCS {
    string S, T;
    vector <vector<int>> dp;

public:
    LCS(string &s, string &t) : S(s), T(t) {
        int sl = S.size(), tl = T.size();
        dp.assign(sl + 1, vector<int>(tl + 1, 0));

        for (int i = 0; i < sl; i++) {
            for (int j = 0; j < tl; j++) {
                if (S[i] == T[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
    }

    int len() { return dp[S.size()][T.size()]; }

    string str() {
        string ret = "";
        int i = S.size(), j = T.size();
        while (dp[i][j]) {
            if (S[i - 1] == T[j - 1]) {
                i--, j--;
                ret = S[i] + ret;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        return ret;
    }
};


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=jp
void AOJ_ALDS1_10_C() {
    int q;
    cin >> q;
    while (q--) {
        string x, y;
        cin >> x >> y;
        LCS lcs(x, y);
        cout << lcs.len() << "\n";
    }
}


// verified
//   https://atcoder.jp/contests/dp/tasks/dp_f
void AtCoder_2019_1_6_F() {
    string s, t;
    cin >> s >> t;
    LCS lcs(s, t);
    cout << lcs.str() << '\n';
}

int main() {
    AOJ_ALDS1_10_C();
    // AtCoder_2019_1_6_F();
    return 0;
}