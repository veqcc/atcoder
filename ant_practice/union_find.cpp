#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int MAX_N=10000;

int par[MAX_N];
int rnk[MAX_N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    init(3);
    unite(1,2);
    unite(2,3);

    cout << same(1,3) << "\n"; // 1
    return 0;
}