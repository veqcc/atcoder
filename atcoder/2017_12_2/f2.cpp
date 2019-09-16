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

const int MAX_ROW = 20;
const int MAX_COL = 100005;

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
        for (int row = 0; row < A.H; row++) {
            if (row != rank && A[row][col]) A[row] ^= A[rank];
        }
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
    for (int row = rank; row < m; row++) {
        if (M[row][n]) return -1; // check if it has no solution
    }
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
    int n, k, a;
    cin >> n >> k;
    vector<int> b(MAX_ROW);
    for (int j = 0; j < MAX_ROW; j++) {
        if ((1 << j) & k) b[j] = 1;
    }
    BitMatrix A(MAX_ROW, n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        for (int j = 0; j < MAX_ROW; j++) {
            if ((1 << j) & a) A[j][i] = 1;
        }
    }
    int rank = linear_equation(A, b);
    cout << (rank == -1 ? 0 : pow_mod(2, n - rank, MOD)) << '\n';
}