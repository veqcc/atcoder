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

int n, bit[1 << 20];
vector<int> children[1 << 20];

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i; // 最後の1ビット
    }
    return s;
}

void add(int i, int x) {
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

ll dfs(int i) {
    ll sm = 0LL;
    add(i+1, 1);
    for (int j: children[i]) {
        sm += sum(j+1);
        sm += dfs(j);
    }
    add(i+1, -1);
    return sm;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        children[p].push_back(i);
    }

    cout << dfs(0) << "\n";
    return 0;
}