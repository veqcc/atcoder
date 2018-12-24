#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
ll n, W, w0, ans = 0;
vector <ll> v[4];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        ll w, V;
        cin >> w >> V;
        if (i == 0) w0 = w;
        v[w - w0].push_back(V);
    }

    for (int i = 0; i < 4; i++) {
        sort(v[i].begin(), v[i].end());
        v[i].push_back(0);
        reverse(v[i].begin(), v[i].end());

        for (int j = 1; j < v[i].size(); j++) {
            v[i][j] += v[i][j-1];
        }
    }

    for (int i = 0; i < v[0].size(); i++) {
        for (int j = 0; j < v[1].size(); j++) {
            for (int k = 0; k < v[2].size(); k++) {
                for (int l = 0; l < v[3].size(); l++) {
                    ll tmp = v[0][i] + v[1][j] + v[2][k] + v[3][l];
                    if (W >= w0 * (ll)(i + j + k + l) + (ll)(j + 2 * k + 3 * l)) {
                        ans = max(ans, tmp);
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}