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

const int MAX_ROW = 500;
const int MAX_COL = 500;

struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m, int n) : H(m), W(n) {}
    inline bitset<MAX_COL> & operator [] (int i) { return val[i]; }
};
int GaussJordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = 0; col < A.W; col++) {
        if (is_extended && col == A.W - 1) break; // 拡大係数行列。この場合、最後の列は掃き出さない
        int pivot = -1;
        for (int row = rank; row < A.H; row++) if (A[row][col]) { pivot = row; break; }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for (int row = 0; row < A.H; row++) if (row != rank && A[row][col]) A[row] ^= A[rank];
        rank++;
    }
    return rank;
}
int linear_equation(BitMatrix A, vector<int> b) {
    int m = A.H, n = A.W;
    BitMatrix M(m, n + 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);
    for (int row = rank; row < m; row++) if (M[row][n]) return -1; // check if it has no solution
    return rank;
}

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

int main() {
    int n, m, x, a, t, l, r;
    cin >> n >> m >> x;
    vector<int> b(30 + m);
    for (int i = 0; i < 30; i++) if (x & (1 << i)) b[i] = 1;
    BitMatrix A(30 + m, n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        for (int j = 0; j < 30; j++) if (a & (1 << j)) A[j][i] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> t >> l >> r;
        b[30 + i] = t;
        for (int j = l - 1; j < r; j++) A[30 + i][j] = 1;
    }
    int rank = linear_equation(A, b);
    cout << (rank == -1 ? 0 : pow_mod(2, n - rank, 1e9 + 7)) << '\n';
    return 0;
}