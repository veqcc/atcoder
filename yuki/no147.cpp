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
typedef unsigned int uint;
using namespace std;

const ll MOD = 1000000007LL;
ll mod(ll a, ll m) { return (a % m + m) % m; }

template<class T> struct Matrix {
    vector <vector<T>> val;
    Matrix(int n = 1, int m = 1) { val.clear(); val.resize(n, vector<T>(m)); }
    Matrix(int n, int m, T x) { val.clear(); val.resize(n, vector<T>(m, x)); }
    void init(int n, int m, T x = 0) { val.clear(); val.resize(n, vector<T>(m, x)); }
    void resize(int n, int m, T x = 0) { val.resize(n); for (int i = 0; i < n; ++i) val[i].resize(m, x); }
    int size() { return val.size(); }
    inline vector <T> &operator[](int i) { return val[i]; }
    friend ostream &operator<<(ostream &s, Matrix<T> M) { s << endl; for (int i = 0; i < M.val.size(); ++i) s << M[i] << endl; return s; }
};

template<class T> Matrix<T> operator * (Matrix<T> A, Matrix<T> B) {
    Matrix<T> R(A.size(), B[0].size());
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < B[0].size(); ++j)
            for (int k = 0; k < B.size(); ++k)
                R[i][j] = mod(R[i][j] + A[i][k] * B[k][j], MOD);
    return R;
}

template<class T> vector<T> operator * (Matrix<T> A, vector<T> B) {
    vector <T> v(A.size());
    for (int i = 0; i < A.size(); ++i)
        for (int k = 0; k < B.size(); ++k)
            v[i] = (v[i] + A[i][k] * B[k]) % MOD;
    return v;
}

template<class T> Matrix<T> pow(Matrix<T> A, ll n) {
    Matrix<T> R(A.size(), A.size());
    for (int i = 0; i < A.size(); ++i) R[i][i] = 1;
    while (n > 0) { if (n & 1) R = R * A; A = A * A; n >>= 1; }
    return R;
}

ll powi(ll x, string s) {
    ll ret = 1LL;
    int n = s.size();
    for (int i = n-1; i >= 0; i--) {
        int c = s[i] - '0';
        ll tmp = 1LL;
        for (int j = 0; j < 10; j++) {
            if (j == c) ret = ret * tmp % MOD;
            tmp = tmp * x % MOD;
        }
        x = tmp;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;

    ll ans = 1LL;
    Matrix <ll> M(2, 2, 1LL);
    M[0][0] = 0LL;
    vector <ll> v(2, 1LL);
    for (int i = 0; i < n; i++) {
        ll c;
        string d;
        cin >> c >> d;

        Matrix <ll> P = pow(M, c-1);
        vector <ll> V = P * v;
        ll sm = (V[0] + V[1]) % MOD;
        ans = ans * powi(sm, d) % MOD;
    }

    cout << ans << "\n";
    return 0;
}