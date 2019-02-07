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
typedef pair <int, int> P;

const ll mod = 777777777;

int good[3][3];
vector <ll> dat[(1 << 18) - 1];

void update(int node, vector <ll> vec) {
    node += (1 << 17) - 1;
    dat[node] = vec;
    while (node > 0) {
        node = (node - 1) / 2;
        if (dat[node*2+2].size() == 0) {
            dat[node] = dat[node*2+1];
        } else {
            dat[node] = {};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    // 左端がi, 右端がj, それをgood[k][l]で接続する数
                    ll tmp = 0LL;
                    for (int k = 0; k < 3; k++) {
                        for (int l = 0; l < 3; l++) {
                            tmp += (dat[node*2+1][i*3+k] * good[k][l] * dat[node*2+2][l*3+j]) % mod;
                        }
                    }
                    dat[node].push_back(tmp % mod);
                }
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> good[i][j];
        }
    }

    vector <P> query;
    for (int i = 0; i < m; i++) {
        int v, t;
        cin >> v >> t;
        query.push_back(P(v, t));
    }

    for (int i = 0; i < n; i++) {
        vector <ll> vec = {1,0,0,0,1,0,0,0,1};
        update(i, vec);
    }

    for (int i = 0; i < m; i++) {
        vector <ll> vec = {0,0,0,0,0,0,0,0,0};
        int t = query[i].second;
        if (t == 1 || t == 0) vec[0] = 1;
        if (t == 2 || t == 0) vec[4] = 1;
        if (t == 3 || t == 0) vec[8] = 1;

        update(query[i].first - 1, vec);

        ll ret = 0LL;
        for (int i = 0; i < 9; i++) {
            ret += dat[0][i];
        }
        cout << ret % mod << "\n";
    }

    return 0;
}