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

int n, m, A[3][3];

// 01の行列のrankを求める (つまり演算はxor)

int gaussian_elimination() {
    int rank = 0;
    for (int j = 0; j < m; j++) {
        int pivot = -1;
        for (int i = rank; i < n; i++) {
            if (A[i][j]) {
                pivot = i;
                break;
            }
        }
        if (pivot >= 0) {
            if (pivot != rank) for (int k = 0; k < m; k++) swap(A[pivot][k], A[rank][k]);
            for (int i = rank + 1; i < n; i++) {
                if (A[i][j]) for (int k = 0; k < m; k++) A[i][k] ^= A[rank][k];
            }
            rank++;
        }
    }
    return rank;
}

int main() {
    n = 3; m = 3;
    A[0][0] = 0; A[0][1] = 0; A[0][2] = 0;
    A[1][0] = 1; A[1][1] = 1; A[1][2] = 1;
    A[2][0] = 0; A[2][1] = 1; A[2][2] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    cout << " ↓\n";

    int rank = gaussian_elimination();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nrank = " << rank << "\n";
    return 0;
}