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
                R[i][j] += A[i][k] * B[k][j];
    return R;
}

template<class T> vector<T> operator * (Matrix<T> A, vector<T> B) {
    vector <T> v(A.size());
    for (int i = 0; i < A.size(); ++i)
        for (int k = 0; k < B.size(); ++k)
            v[i] += A[i][k] * B[k];
    return v;
}

template<class T> Matrix<T> pow(Matrix<T> A, int n) {
    Matrix<T> R(A.size(), A.size());
    for (int i = 0; i < A.size(); ++i) R[i][i] = 1;
    while (n > 0) { if (n & 1) R = R * A; A = A * A; n >>= 1; }
    return R;
}

int main() {
    int r, c, t, sy, sx, gy, gx;
    cin >> r >> c >> t >> sy >> sx >> gy >> gx;
    string b[r];
    for (int i = 0; i < r; i++) {
        cin >> b[i];
    }

    int n = r * c;
    Matrix <double> M(n, n, 0.0);
    for (int i = 0; i < n; i++) {
        int x = i / c, y = i % c;
        if (b[x][y] == '#') continue;

        int count = 0;
        if (b[x-1][y] == '.') count++;
        if (b[x][y-1] == '.') count++;
        if (b[x+1][y] == '.') count++;
        if (b[x][y+1] == '.') count++;

        if (count == 0) {
            M[i][i] = 1.0;
        } else {
            double prob = 1.0 / (double)count;
            if (b[x-1][y] == '.') M[i-c][i] = prob;
            if (b[x][y-1] == '.') M[i-1][i] = prob;
            if (b[x+1][y] == '.') M[i+c][i] = prob;
            if (b[x][y+1] == '.') M[i+1][i] = prob;
        }
    }

    vector <double> vec(n, 0.0);
    vec[sy*c+sx] = 1.0;

    Matrix <double> P = pow(M, t);
    vector <double> V = P * vec;

    cout << fixed << setprecision(15) << V[gy*c+gx] << "\n";
    return 0;
}