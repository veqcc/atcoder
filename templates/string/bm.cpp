#include <iostream>
#include <vector>
using namespace std;

// BM法.
//  patternに対して末尾から一致しているか判定する。
//  文字の種類が多い時は O(|S|/|P|) だが
//  同じ文字が何度も出現する場合 O(|S||P|) なので遅い

class BM {
    int p_len;
    string p;
    vector <int> skip; // 文字iはpatternの後ろから何番目に現れるか

public:
    BM(const string &pattern) {
        p = pattern;
        p_len = p.size();
        skip.assign(128, -1);
        for (int i = 0; i < p_len; i++) {
            skip[p[i]] = p_len - i - 1;
        }
    }

    vector <int> match(const string &s) {
        int i = p_len - 1;
        int s_len = s.size();
        vector <int> ret;
        while (i < s_len) {
            int j = p_len - 1;
            while (s[i] == p[j]) {
                if (j == 0) {
                    ret.push_back(i);
                    break;
                }
                i--; j--;
            }
            i += max(p_len - j, skip[s[i]]);
        }
        return ret;
    }
};


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_A&lang=jp
void AOJ_ALDS1_14_A() {
    string T, P;
    cin >> T >> P;
    BM bm(P);
    vector <int> ans = bm.match(T);
    for (int i : ans) cout << i << "\n";
}

int main() {
    AOJ_ALDS1_14_A();
    return 0;
}