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

const int n = 1 << 18;
int bit[n+1];

void add(int x, int a) { // x番目にaを足す
    while (x <= n) {
        bit[x] += a;
        x += x & -x;
    }
}

int find(int x) { // x番目の数を返す
    int i = n / 2;
    int sm = 0;
    while (true) {
        if (sm + bit[i] >= x) {
            i -= (i & -i) / 2;
        } else {
            sm += bit[i];
            i += (i & -i) / 2;
        }

        if ((i & -i) == 1) {
            if (sm + bit[i] >= x) {
                return i;
            } else {
                return i + 1;
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            add(x, 1);
        } else {
            int ret = find(x);
            cout << ret << "\n";
            add(ret, -1);
        }
    }

    return 0;
}