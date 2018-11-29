#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class BIT {
    const int N;
    vector<int> bit;
public:
    BIT(int maxi) : N(maxi), bit(N + 1) {}

    void add(int a, int w) {
        for (int x = a; x <= N; x += x & -x) bit[x] += w;
    }

    int kth_element(int k) {
        int x = 1 << (31 - __builtin_clz(N));
        int ret = 0; k--;
        while (x) {
            if (ret + x <= N && k >= bit[ret + x]) k -= bit[ret + x], ret += x;
            x >>= 1;
        }
        return ret+1;
    }
};

int main() {
    int Q, T, X;
    cin >> Q;
    BIT bit(200010);
    for (int i = 0; i < Q; i++) {
        cin >> T >> X;
        if (T == 1) bit.add(X, 1);
        else {
            int k = bit.kth_element(X);
            cout << k << "\n";
            bit.add(k, -1);
        }
    }
    return 0;
}
