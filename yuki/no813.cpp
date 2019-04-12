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
typedef long double ld;
using namespace std;

ld dp[1005][1005];
// i->j->iとなる確率

int main() {
    int n;
    ld p, q;
    cin >> n >> p >> q;

    if (q == 0) {
        cout << 1 << "\n";
        return 0;
    }

    ld P = p, Q = q;
    for (int i = 1; i < n; i++) {
        ld nextQ = Q * q / (1 - P * p);
        ld nextP = P + p * Q * Q / (1 - P * p);
        P = nextP;
        Q = nextQ;
    }

    cout << P << "\n";
    return 0;
}