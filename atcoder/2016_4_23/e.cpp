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

template<class MeetSemiLattice> struct SparseTable {
    const MeetSemiLattice INF = 1<<30;
    vector<vector<MeetSemiLattice> > dat;
    vector<int> height;

    SparseTable() { }
    SparseTable(const vector<int> &vec) { init(vec); }
    void init(const vector<int> &vec) {
        int n = (int)vec.size(), h = 0;
        while ((1<<h) < n) ++h;
        dat.assign(h, vector<MeetSemiLattice>(1<<h));
        height.assign(n+1, 0);
        for (int i = 2; i <= n; i++) height[i] = height[i>>1]+1;
        for (int i = 0; i < n; ++i) dat[0][i] = vec[i];
        for (int i = 1; i < h; ++i)
            for (int j = 0; j < n; ++j)
                dat[i][j] = min(dat[i-1][j], dat[i-1][min(j+(1<<(i-1)),n-1)]);
    }

    MeetSemiLattice get(int a, int b) {
        if (a >= b) return INF;
        return min(dat[height[b-a]][a], dat[height[b-a]][b-(1<<height[b-a])]);
    }
};

struct SuffixArray {
    string str;
    vector<int> sa; // sa[i] : the starting index of the i-th smallest suffix (i = 0, 1, ..., n)
    vector<int> lcp; // lcp[i]: the lcp of sa[i] and sa[i+1] (i = 0, 1, ..., n-1)
    inline int &operator[](int i) { return sa[i]; }

    SuffixArray(const string &str_) : str(str_) {
        buildSA();
        calcLCP();
    }

    void init(const string &str_) {
        str = str_;
        buildSA();
        calcLCP();
    }

    // build SA
    vector<int> rank_sa, tmp_rank_sa;

    struct CompareSA {
        int n, k;
        const vector<int> &rank;

        CompareSA(int n, int k, const vector<int> &rank_sa) : n(n), k(k), rank(rank_sa) {}

        bool operator()(int i, int j) {
            if (rank[i] != rank[j]) return (rank[i] < rank[j]);
            else {
                int rank_ik = (i + k <= n ? rank[i + k] : -1);
                int rank_jk = (j + k <= n ? rank[j + k] : -1);
                return (rank_ik < rank_jk);
            }
        }
    };

    void buildSA() {
        int n = (int) str.size();
        sa.resize(n + 1), lcp.resize(n + 1), rank_sa.resize(n + 1), tmp_rank_sa.resize(n + 1);
        for (int i = 0; i < n; ++i) sa[i] = i, rank_sa[i] = (int) str[i];
        sa[n] = n, rank_sa[n] = -1;
        for (int k = 1; k <= n; k *= 2) {
            CompareSA csa(n, k, rank_sa);
            sort(sa.begin(), sa.end(), csa);
            tmp_rank_sa[sa[0]] = 0;
            for (int i = 1; i <= n; ++i) {
                tmp_rank_sa[sa[i]] = tmp_rank_sa[sa[i - 1]];
                if (csa(sa[i - 1], sa[i])) ++tmp_rank_sa[sa[i]];
            }
            for (int i = 0; i <= n; ++i) rank_sa[i] = tmp_rank_sa[i];
        }
    }

    // build LCP
    vector<int> rsa;
    SparseTable<int> st;

    void calcLCP() {
        int n = (int) str.size();
        rsa.resize(n + 1);
        for (int i = 0; i <= n; ++i) rsa[sa[i]] = i;
        lcp.resize(n + 1);
        lcp[0] = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int pi = sa[rsa[i] - 1];
            if (cur > 0) --cur;
            for (; pi + cur < n && i + cur < n; ++cur) {
                if (str[pi + cur] != str[i + cur]) break;
            }
            lcp[rsa[i] - 1] = cur;
        }
        st.init(lcp);
    }

    int getLCP(int a, int b) { // lcp of str.substr(a) and str.substr(b)
        return st.get(min(rsa[a], rsa[b]), max(rsa[a], rsa[b]));
    }
};


int main() {
    string s;
    cin >> s;
    ll n = s.size();
    ll ret = 0;
    for (ll i = 1; i <= n; i++) {
        ret += i * (n - i + 1);
    }

    SuffixArray sa(s);
    for (int i = 0; i < n; i++) {
        ll x = (ll)sa.lcp[i];
        ret -= x * (x + 1) / 2;
    }

    cout << ret << "\n";
    return 0;
}