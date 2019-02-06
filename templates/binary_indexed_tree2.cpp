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

// 蟻本ver

const int MAX_N = 100005;
int n, bit[MAX_N + 1];

// iが与えられた時に、a[1]+a[2]+...+a[i]を計算する
int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i; // 最後の1ビット
    }
    return s;
}

// iとxが与えられた時に、a[i]にxを足す
void add(int i, int x) {
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

int main() {
    n = 10;
    for (int i = 1; i <= n; i++) {
        add(i, i);
    }

    cout << sum(10) << "\n"; // 55
    add(3, 3);
    cout << sum(10) << "\n"; // 58
    cout << sum(5) << "\n"; // 18

    return 0;
}