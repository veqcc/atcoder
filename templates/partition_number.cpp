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

const int n = 100;
int P[n][n]; // P(n,m) : nをm以下の自然数に分割する場合の数
int Q[n][n]; // Q(n,r) : nをr個の自然数に分割する場合の数

void partition_number_P() {
    // P(0,m) = P(n,1) = 1
    // P(n,m) = P(n-m,m) + P(n,m-1) if n >= m > 1
    // P(n,m) = P(n,n) if n < m

    for (int k = 0; k < n; k++) {
        P[0][k] = 1;
        P[k][1] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 2; j <= i; j++) {
            P[i][j] = P[i-j][j] + P[i][j-1];
        }

        for (int j = i+1; j < n; j++) {
            P[i][j] = P[i][j-1];
        }
    }
}

void partition_number_Q() {
    // Q(n,1) = Q(n,n) = 1 if n >= 1
    // Q(n,r) = Q(n-1,r-1) + Q(n-r,r) if n >= r >= 2

    for (int k = 1; k < n; k++) {
        Q[k][1] = 1;
        Q[k][k] = 1;
    }

    for (int i = 2; i < n; i++) {
        for (int j = 2; j <= i; j++) {
            Q[i][j] = Q[i-1][j-1] + Q[i-j][j];
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    partition_number_P();
    partition_number_Q();

    for (int i = 1; i <= 7; i++) {
        cout << P[7][i] << " "; // 7をi以下の自然数に分割 -> 1 4 8 11 13 14 15
    }
    cout << "\n";

    for (int i = 1; i <= 7; i++) {
        cout << Q[7][i] << " "; // 7をi個の自然数に分割 -> 1 3 4 3 2 1 1
    }
    cout << "\n";

    cout << Q[7+4][4] << "\n"; // 7を4個の非負整数に分割 -> 11

    return 0;
}