#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;

// binary行列の掃き出し法と行列累乗
// bitset高速化により、定数倍速い

const int MAX_ROW = 500;
const int MAX_COL = 500;
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m, int n) : H(m), W(n) {}
    inline bitset<MAX_COL> & operator [] (int i) { return val[i]; }
};
inline BitMatrix operator * (BitMatrix A, BitMatrix B) {
    BitMatrix R(A.H, B.W);
    BitMatrix tB(B.W, B.H);
    for (int i = 0; i < tB.H; i++) for (int j = 0; j < tB.W; j++) tB[i][j] = B[j][i];
    for (int i = 0; i < R.H; i++) for (int j = 0; j < R.W; j++) R[i][j] = ((A[i] & tB[j]).count() & 1);
    return R;
}
inline BitMatrix pow(BitMatrix A, ll  n) {
    BitMatrix R(A.H, A.H);
    for (int i = 0; i < A.H; ++i) R[i][i] = 1;
    while (n > 0) { if (n & 1) R = R * A; A = A * A; n >>= 1; }
    return R;
}
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
int linear_equation(BitMatrix A, vector<int> b, vector<int> &res) {
    int m = A.H, n = A.W;
    BitMatrix M(m, n + 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);
    for (int row = rank; row < m; row++) if (M[row][n]) return -1; // check if it has no solution
    res.assign(n, 0);
    for (int i = 0; i < rank; i++) res[i] = M[i][n];
    return rank;
}


// verified
//  https://atcoder.jp/contests/code-thanks-festival-2017/tasks/code_thanks_festival_2017_f

// verified
//  https://atcoder.jp/contests/abc141/tasks/abc141_f

// verified
//  https://yukicoder.me/problems/no/184

// verified
//  https://yukicoder.me/problems/no/803

int main() {
    yuki184();
    return 0;
}