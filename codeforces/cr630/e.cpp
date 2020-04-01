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
ll MOD = 998244353LL;

ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1;
    num %= mod;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % mod;
        num = num * num % mod;
        pow >>= 1;
    }
    return prod;
}

template<class T> struct Matrix {
    vector<vector<T> > val;
    Matrix(int n = 1, int m = 1) {val.clear(); val.resize(n, vector<T>(m));}
    size_t size() {return val.size();}
    inline vector<T>& operator [] (int i) {return val[i];}
};

template<class T> Matrix<T> operator * (Matrix<T> &A, Matrix<T> &B) {
    Matrix<T> R(A.size(), B[0].size());
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < B[0].size(); ++j)
            for (int k = 0; k < B.size(); ++k) {
                R[i][j] += A[i][k] * B[k][j] % MOD;
                R[i][j] %= MOD;
            }
    return R;
}

template<class T> Matrix<T> pow(Matrix<T> &A, ll n) {
    Matrix<T> R(A.size(), A.size());
    for (int i = 0; i < A.size(); ++i) R[i][i] = 1;
    while (n > 0) {
        if (n & 1) R = R * A;
        A = A * A;
        n >>= 1;
    }
    return R;
}

template<class T> vector<T> operator * (Matrix<T> &A,  vector<T> &B) {
    vector <T> v(A.size());
    for (int i = 0; i < A.size(); ++i)
        for (int k = 0; k < B.size(); ++k) {
            v[i] += A[i][k] * B[k] % MOD;
            v[i] %= MOD;
        }
    return v;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m, l, r;
    cin >> n >> m >> l >> r;

    if (n * m % 2 == 1) {
        cout << pow_mod(r - l + 1, n * m, MOD) << '\n';
    } else {
//        ll num = n * m;
//        ll even = r % 2 == 0 ? (r - l + 2) / 2 : (r - l + 1) / 2;
//        ll odd = r - l + 1 - even;
//
//        Matrix<ll> M(2, 2);
//        M[0][0] = M[1][1] = even;
//        M[0][1] = M[1][0] = odd;
//
//        Matrix<ll> ret = pow(M, num);
//
//        vector <ll> init = {1, 0};
//        vector <ll> ans = ret * init;
//
//        cout << ans[0] << '\n';

        ll k = r - l + 1;
        if (k % 2 == 0) {
            cout << pow_mod(k, n * m, MOD) * pow_mod(2, MOD - 2, MOD) % MOD << endl;
        } else {
            cout << (pow_mod(k, n * m, MOD) + 1) * pow_mod(2, MOD - 2, MOD) % MOD << endl;
        }
    }

    return 0;
}