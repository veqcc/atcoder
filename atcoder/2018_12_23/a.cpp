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

vector <int> edges[100005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    ll k;
    string s;
    cin >> n >> m >> k >> s;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector <bool> all_blue(n, true);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            for (int j : edges[i]) {
                all_blue[j] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        bool red = true;

        if (k % 2 == 0) {
            if (s[i] == 'B') {
                for (int node : edges[i]) {
                    if (all_blue[node]) {
                        red = false;
                        break;
                    }
                }
            }
        } else {
            for (int node : edges[i]) {
                if (s[node] == 'B') {
                    red = false;
                    break;
                }
            }
        }

        cout << (red ? "Second" : "First") << "\n";
    }

    return 0;
}