#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int n;
bool used[505][505];
int potential[505];
int level[505][505];
int c;

void dfs(int cur, int val) {
    for (int i = 0; i < n; i++) {
        if (i == cur) continue;
        if (level[i][cur] < 0 && level[cur][i] < 0) {
            if (potential[i] < 0) {
                potential[i] = potential[cur] + 1;
                level[i][cur] = level[cur][i] = val;
                c++;
                dfs(i, val);
            } else {
                if (potential[i] % 2 != potential[cur] % 2) {
                    level[i][cur] = level[cur][i] = val;
                    c++;
                }
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    fill(level[0], level[n], -1);

    c = 0;
    int l = 1;
    while (c < n * (n - 1) / 2) {
        fill(potential, potential + n, -1);
        for (int j = 0; j < n; j++) {
            if (potential[j] < 0) {
                potential[j] = 0;
                dfs(j, l);
            }
        }
        l++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << level[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}