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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int A[n][m];
    int a_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            a_count += A[i][j];
        }
    }

    int B[n][m];
    fill(B[0], B[n], 0);
    int b_count = 0;
    vector <pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (A[i][j] + A[i + 1][j] + A[i][j + 1] + A[i + 1][j + 1] == 4) {
                b_count += A[i][j] - B[i][j];
                b_count += A[i + 1][j] - B[i + 1][j];
                b_count += A[i][j + 1] - B[i][j + 1];
                b_count += A[i + 1][j + 1] - B[i + 1][j + 1];
                B[i][j] = B[i + 1][j] = B[i][j + 1] = B[i + 1][j + 1] = 1;
                ans.push_back({i + 1, j + 1});
            }
        }
    }

    if (a_count != b_count) {
        cout << -1 << "\n";
    } else {
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << ' ' << ans[i].second << "\n";
        }
    }

    return 0;
}