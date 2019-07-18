#include <iostream>
#include <string>
#include <vector>
using namespace std;

// KMP法. MP法の改良版
//   pattern[0:i] の suffix と pattern の prefix がどれだけ一致しているかを探す
//   ex: "aabaabaa" の fail は [-1,0,1,0,1,2,3,4,5]
//   計算量は ならしO(|S|)、最悪O(|S|log(|S|)) ?
//   cf: https://snuke.hatenablog.com/entry/2017/07/18/101026

// MP法.
//   計算量は ならしO(|S|)、最悪O(|S|^2) ?
//   cf: https://snuke.hatenablog.com/entry/2014/12/01/235807

// int period(int i)
//   pattern[0:i] の最小周期長
//   ex: abababcaa -> 122222778
//   cf: https://snuke.hatenablog.com/entry/2015/04/05/184819

// vector match(string s)
//   s の中で pattern が現れる index の vector を返す　

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

    void initMP(const string &p) {
        pattern = p;
        int m = pattern.size();
        fail.assign(m + 1, -1);
        for (int i = 0, j = -1; i < m; i++) {
            while (j >= 0 && pattern[i] != pattern[j]) j = fail[j];
            fail[i+1] = ++j;
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


// verified
//   https://yukicoder.me/problems/no/430
//   (ただし、計算量はギリギリなので、KMPのもっといいverifyありそう)
void yuki430() {
    string s;
    cin >> s;

    int m;
    cin >> m;

    int ans = 0;
    for (int i = 0; i < m; i++) {
        string pattern;
        cin >> pattern;

        KMP kmp(pattern);
        vector <int> res = kmp.match(s);
        ans += res.size();
    }

    cout << ans << "\n";
}


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp
void AOJ_ALDS1_14_B() {
    string T, P;
    cin >> T >> P;
    KMP kmp(P);
    vector <int> ans = kmp.match(T);
    for (int i : ans) cout << i << "\n";
}

int main() {
    // yuki430();
    AOJ_ALDS1_14_B();
    return 0;
}