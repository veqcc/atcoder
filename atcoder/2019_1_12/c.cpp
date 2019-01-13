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

typedef pair<ll, ll> P;

int h, w;
string s[405];
bool visited[405][405];

P dfs(int x, int y) {
    P p = make_pair(0LL, 0LL);

    if (visited[x][y]) {
        return p;
    }

    visited[x][y] = true;

    if (s[x][y] == '.') {
        p.first++;
        if (x < h-1 && s[x+1][y] == '#') {
            P p2 = dfs(x+1, y);
            p.first += p2.first;
            p.second += p2.second;
        }

        if (y < w-1 && s[x][y+1] == '#') {
            P p2 = dfs(x, y+1);
            p.first += p2.first;
            p.second += p2.second;
        }

        if (x > 0 && s[x-1][y] == '#') {
            P p2 = dfs(x-1, y);
            p.first += p2.first;
            p.second += p2.second;
        }

        if (y > 0 && s[x][y-1] == '#') {
            P p2 = dfs(x, y-1);
            p.first += p2.first;
            p.second += p2.second;
        }
    } else {
        p.second++;
        if (x < h-1 && s[x+1][y] == '.') {
            P p2 = dfs(x+1, y);
            p.first += p2.first;
            p.second += p2.second;
        }

        if (y < w-1 && s[x][y+1] == '.') {
            P p2 = dfs(x, y+1);
            p.first += p2.first;
            p.second += p2.second;
        }

        if (x > 0 && s[x-1][y] == '.') {
            P p2 = dfs(x-1, y);
            p.first += p2.first;
            p.second += p2.second;
        }

        if (y > 0 && s[x][y-1] == '.') {
            P p2 = dfs(x, y-1);
            p.first += p2.first;
            p.second += p2.second;
        }
    }

    return p;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    ll ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!visited[i][j]) {
                P p = dfs(i, j);
                ans += (p.first * p.second);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}