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

class UnionFind {
    vector<int> par;
    int n;

public:
    UnionFind(int n) : par(n, -1) {}

    int find(int x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(30);

        bool ans = true;
        for (int i = 0; i < equations.size(); i++) {
            string s = equations[i];
            if (s[1] == '=') {
                uf.unite(s[0]-'a', s[3]-'a');
            }
        }

        for (int i = 0; i < equations.size(); i++) {
            string s = equations[i];
            if (s[1] == '!') {
                if (uf.same(s[0]-'a', s[3]-'a')) {
                    ans = false;
                }
            }
        }

        return ans;
    }
};

