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
typedef unsigned long long ull;
using namespace std;

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
    for (int col = A.W - 1; col >= 0; col--) {
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
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ull total = 0;
    vector <ull> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total ^= a[i];
    }

    BitMatrix A(n, MAX_COL);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            if (!(total & (1LL << j)) && (a[i] & (1LL << j))) {
                A[i][j] = 1;
            }
        }
    }

    int rank = GaussJordan(A);

    ull blue = 0;
    for (int i = 0; i < rank; i++) {
        blue = max(blue, blue ^ A[i].to_ullong());
    }

    cout << blue + (total ^ blue) << "\n";
    return 0;
}