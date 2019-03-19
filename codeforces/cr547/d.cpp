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
typedef pair <int, int> P;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string l, r;
    cin >> n >> l >> r;

    vector <int> pos[2][27];
    for (int i = 0; i < n; i++) {
        if (l[i] == '?') {
            pos[0][26].push_back(i + 1);
        } else {
            pos[0][l[i] - 'a'].push_back(i + 1);
        }

        if (r[i] == '?') {
            pos[1][26].push_back(i + 1);
        } else {
            pos[1][r[i] - 'a'].push_back(i + 1);
        }
    }

    vector <P> ans;
    vector <int> remain[2];
    for (int i = 0; i < 26; i++) {
        int mn = min(pos[0][i].size(), pos[1][i].size());
        for (int j = 0; j < mn; j++) ans.push_back(P(pos[0][i][j], pos[1][i][j]));
        for (int j = mn; j < pos[0][i].size(); j++) remain[0].push_back(pos[0][i][j]);
        for (int j = mn; j < pos[1][i].size(); j++) remain[1].push_back(pos[1][i][j]);
    }

    int lmn = min(pos[0][26].size(), remain[1].size());
    for (int i = 0; i < lmn; i++) ans.push_back(P(pos[0][26][i], remain[1][i]));

    int rmn = min(pos[1][26].size(), remain[0].size());
    for (int i = 0; i < rmn; i++) ans.push_back(P(remain[0][i], pos[1][26][i]));

    while (lmn < pos[0][26].size() && rmn < pos[1][26].size()) {
        ans.push_back(P(pos[0][26][lmn++], pos[1][26][rmn++]));
    }

    cout << ans.size() << '\n';
    for (P p : ans) cout << p.first << " " << p.second << '\n';

    return 0;
}