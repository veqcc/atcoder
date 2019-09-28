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

    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int cur = 0;
    for (int i = 0; i < n; i++) {
        int mn = 1e9;
        for (int j = 0; j < m; j++) {
            int b;
            cin >> b;
            int start = cur;
            if (cur % A[i][j] != 0) start += A[i][j] - cur % A[i][j];
            mn = min(mn, start + b);
        }
        cur = mn;
    }

    cout << cur << "\n";
    return 0;
}