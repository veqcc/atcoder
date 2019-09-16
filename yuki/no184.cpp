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
const ll MOD = 1000000007LL;

const int MAX_ROW = 100005;
const int MAX_COL = 61;

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

int main() {
    int n;
    cin >> n;
    BitMatrix M(n, MAX_COL);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        for (int j = 0; j < MAX_COL; j++) {
            if (a & (1LL << j)) M[i][j] = 1;
        }
    }
    int rank = GaussJordan(M);
    cout << (1LL << rank) << '\n';
}