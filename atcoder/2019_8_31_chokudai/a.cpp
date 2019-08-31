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
typedef pair <int, int> P;

int n, b1, b2, b3;
int l[30][30], r[30][30], ans[30][30];

int up_check(int i, int j, int k) {
    int sum = k, ret = 0;
    for (int idx = i - 1; idx >= 0; idx--) {
        if (ans[idx][j] == -1) break;
        sum += ans[idx][j];
        if (sum == b3) ret += b3;
        if (sum == b2) ret += b2;
        if (sum == b1) ret += b1;
    }
    return ret;
}

int down_check(int i, int j, int k) {
    int sum = k, ret = 0;
    for (int idx = i + 1; idx < n; idx++) {
        if (ans[idx][j] == -1) break;
        sum += ans[idx][j];
        if (sum == b3) ret += b3;
        if (sum == b2) ret += b2;
        if (sum == b1) ret += b1;
    }
    return ret;
}

bool right_check(int i, int j, int k) {
    int sum = k, ret = 0;
    for (int idx = j + 1; idx < n; idx++) {
        if (ans[i][idx] == -1) break;
        sum += ans[i][idx];
        if (sum == b3) ret += b3;
        if (sum == b2) ret += b2;
        if (sum == b1) ret += b1;
    }
    return ret;
}

bool left_check(int i, int j, int k) {
    int sum = k, ret = 0;
    for (int idx = j - 1; idx >= 0; idx--) {
        if (ans[i][idx] == -1) break;
        sum += ans[i][idx];
        if (sum == b3) ret += b3;
        if (sum == b2) ret += b2;
        if (sum == b1) ret += b1;
    }
    return ret;
}

int main() {
    cin >> n >> b1 >> b2 >> b3;
    vector <P> vec;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> l[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> r[i][j];
            int diff = r[i][j] - l[i][j];
            if (diff >= 5) l[i][j] = r[i][j] - 4;
            vec.push_back({r[i][j] - l[i][j], i * n + j});
        }
    }

    sort(vec.begin(), vec.end());
    fill(ans[0], ans[29] + 30, -1);

    for (int q = 0; q < n * n; q++) {
        int i = vec[q].second / n;
        int j = vec[q].second % n;

        int mx = 0, val = -1;
        for (int k = l[i][j]; k <= r[i][j]; k++) {
            int sum = 0;

            sum += up_check(i, j, k);
            sum += down_check(i, j, k);
            sum += right_check(i, j, k);
            sum += left_check(i, j, k);

            if (sum >= mx) {
                mx = sum;
                val = k;
            }
        }

        ans[i][j] = val;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}