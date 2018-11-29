#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

// binary indexed tree
// fenwick tree
class BIT {
    const int N;
    vector<int> bit;

public:
    BIT(int maxi) : N(maxi), bit(N + 1) {}

    // p & -p means the lowest bit 1
    void add(int a, int w) {
        for (int x = a; x <= N; x += x & -x) {
            bit[x] += w;
        }
    }

    // sum of 1 ~ a
    int sum(int a) {
        int ret = 0;
        for (int x = a; x > 0; x -= x & -x) {
            ret += bit[x];
        }
        return ret;
    }

    // __builtin_clz(x) is used to count the leading zeros of the integer. clz = count leading zero’s
    // Example: It counts number of zeros before the first occurrence of one(set bit).
    int lower_bound(int k) {
        int n = 1 << (31 - __builtin_clz(N));
        int ret = 0;
        for (int i = n; i > 0; i >>= 1) {
            if (ret + i <= N && k > bit[ret + i]) {
                k -= bit[ret + i];
                ret += i;
            }
        }
        return ret+1;
    }
};

int main() {
    BIT bit(200010);

    bit.add(3, 2);
    bit.add(3, -1); // erase 3
    bit.add(2, 2);
    bit.add(4, 2);

    cout << bit.sum(2) << endl; // 2
    cout << bit.sum(3) << endl; // 2 + 1 = 3
    cout << bit.sum(4) << endl; // 2 + 1 + 2 = 5

    cout << bit.lower_bound(1) << endl; // 2
    cout << bit.lower_bound(2) << endl; // 2
    cout << bit.lower_bound(3) << endl; // 3
    cout << bit.lower_bound(4) << endl; // 4
    cout << bit.lower_bound(5) << endl; // 4

    return 0;
}
