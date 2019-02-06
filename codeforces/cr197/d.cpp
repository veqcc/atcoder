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

const int MAX_N = 1 << 17;
int n, m, a, dat[MAX_N*2-1], p, b;

void update(int k, int x) {
    k += n-1;
    dat[k] = x;

    int op = 1;
    while (k > 0) {
        k = (k - 1) / 2;
        if (op == 1) {
            dat[k] = dat[k * 2 + 1] | dat[k * 2 + 2];
        } else {
            dat[k] = dat[k * 2 + 1] ^ dat[k * 2 + 2];
        }
        op *= -1;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    n = 1 << n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        update(i, a);
    }

    for (int i = 0; i < m; i++) {
        cin >> p >> b;
        update(--p, b);
        cout << dat[0] << "\n";
    }

    return 0;
}