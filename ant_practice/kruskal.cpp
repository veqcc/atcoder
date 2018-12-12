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
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) par[x] = y;
    else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}


struct edge {
    int u;
    int v;
    int cost;
};

const int MAX_E=100;
edge es[MAX_E];
int V, E;

bool comp(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
}

int kruscal() {
    sort(es, es+E, comp); // costが小さい順にソート
    init(V);
    int res = 0;
    for (int i = 0; i < E; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main() {
    return 0;
}