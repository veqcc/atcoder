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
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int height[n][m];
    vector <int> tate[m], yoko[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> height[i][j];
            tate[j].push_back(height[i][j]);
            yoko[i].push_back(height[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        sort(tate[i].begin(), tate[i].end());

        vector<int> :: iterator ip;
        ip = unique(tate[i].begin(), tate[i].end());
        tate[i].resize(distance(tate[i].begin(), ip));
    }
    for (int i = 0; i < n; i++) {
        sort(yoko[i].begin(), yoko[i].end());

        vector<int> :: iterator ip;
        ip = unique(yoko[i].begin(), yoko[i].end());
        yoko[i].resize(distance(yoko[i].begin(), ip));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tate_idx = lower_bound(tate[j].begin(), tate[j].end(), height[i][j]) - tate[j].begin();
            int yoko_idx = lower_bound(yoko[i].begin(), yoko[i].end(), height[i][j]) - yoko[i].begin();

            cout << max((int)tate[j].size() + max(0, yoko_idx - tate_idx), (int)yoko[i].size() + max(0, tate_idx - yoko_idx)) << " ";
        }
        cout << "\n";
    }

    return 0;
}