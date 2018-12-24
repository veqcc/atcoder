#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

double p[5000][200];
double length[5000];
vector < pair < double, pair<int, int> > >  vec;

struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) {}
    int find(int x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (par[x] > par[y]) {
            par[y] += par[x];
            par[x] = y;
        } else {
            par[x] += par[y];
            par[y] = x;
        }
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    cout << fixed << setprecision(8);

    uint x = 123456789;
    uint y = 362436069;
    uint z = 521288629;
    uint t, w;
    int v;
    cin >> w;

    bitset<200> bs[5000];
    for (int i = 0; i < 5000; i++) {
        length[i] = 0.0;

        for (int j = 0; j < 200; j++) {
            t = x ^ (x << 11);
            x=y;
            y=z;
            z=w;
            w = (w^(w>>19))^(t^(t>>8));
            v = w%100000 - 50000;
            if (v >= 0) v++;
            p[i][j] = (double)v;
            length[i] += (double)v * (double)v;
            bs[i][j] = (p[i][j] > 0.0);
        }

        length[i] = sqrt(length[i]);
        for (int k = 0; k < i; k++) {
            bitset<200> bt = bs[i] ^ bs[k];
            if (bt.count() < 85) {
                double ab = 0;
                for (int j = 0; j < 200; j++) {
                    ab += p[i][j] * p[k][j];
                }
                double cost = 1.0 - (ab / length[i] / length[k]);
                vec.push_back(make_pair(cost, make_pair(k, i)));
            }
        }
    }

    sort(vec.begin(), vec.end());
    UnionFind uf(5000);

    double ans=0.0;
    for (int i = 0; i < vec.size(); i++) {
        int e1 = vec[i].second.first;
        int e2 = vec[i].second.second;
        if (uf.same(e1, e2)) {
            continue;
        }
        printf("%d %d\n", e1+1, e2+1);
        ans += vec[i].first;
        uf.unite(e1, e2);
    }

    return 0;
}