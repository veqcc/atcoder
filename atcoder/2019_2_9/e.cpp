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

const ll mod = 998244353LL;

ll power_mod(ll num, ll power) {
    ll prod = 1;
    num %= mod;
    while (power > 0) {
        if (power & 1) {
            prod = prod * num % mod;
        }
        num = num * num % mod;
        power >>= 1;
    }
    return prod;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m, A[300][300];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

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
            if (pivot != rank) {
                for (int k = 0; k < m; k++) {
                    swap(A[pivot][k], A[rank][k]);
                }
            }

            for (int i = rank + 1; i < n; i++) {
                if (A[i][j]) {
                    for (int k = 0; k < m; k++) {
                        A[i][k] ^= A[rank][k];
                    }
                }
            }

            rank++;
        }
    }

    cout << (power_mod(2LL, (ll)(n+m-1)) - power_mod(2LL, (ll)(n+m-rank-1)) + mod) % mod << "\n";
    return 0;
}