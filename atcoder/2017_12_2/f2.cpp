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
const int MAX_ROW = 30;
const int MAX_COL = 100005;

struct BitMatrix {
    int n, m;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int n_ = 1, int m_ = 1) { n = n_; m = m_; }
    inline bitset<MAX_COL> &operator [] (int i) { return val[i]; }
    inline friend ostream &operator << (ostream &s, BitMatrix M) {
        s << "\n";
        for (int i = 0; i < M.n; i++) {
            for (int j = 0; j < M.m; j++) s << M.val[i][j];
            s << "\n";
        }
        return s;
    }
};

inline BitMatrix operator * (BitMatrix A, BitMatrix B) {
    BitMatrix R(A.n, B.m);
    BitMatrix tB(B.m, B.n);
    for (int i = 0; i < tB.n; i++) for (int j = 0; j < tB.m; j++) tB[i][j] = B[j][i];
    for (int i = 0; i < R.n; i++) for (int j = 0; j < R.m; j++) R[i][j] = (A[i] & tB[j]).any();
    return R;
}

int linear_equation(BitMatrix A, vector<int> b) {
    int rank = 0;
    for (int i = 0; i < A.n; i++) A[i][A.m] = b[i];
    for (int i = 0; i < A.m; i++) {
        int pivot = -1;
        for (int j = rank; j < A.n; j++) if (A[j][i]) { pivot = j; break; }
        if (pivot != -1) {
            swap(A[pivot], A[rank]);
            for (int j = 0; j < A.n; j++) if (j != rank && A[j][i]) A[j] ^= A[rank];
            rank++;
        }
    }
    for (int i = rank; i < A.n; i++) if (A[i][A.m]) return -1;
    return rank;
}

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

const int digit = 20;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    BitMatrix A(digit, n);
    vector <int> b(digit);
    for (int d = 0; d < digit; d++) {
        for (int i = 0; i < n; i++) if (a[i] & (1 << d)) A[d][i] = 1;
        if (k & (1 << d)) b[d] = 1;
    }

    int rank = linear_equation(A, b);
    if (rank == -1) cout << 0 << "\n";
    else cout << modpow(2LL, n - rank, MOD) << "\n";
    return 0;
}