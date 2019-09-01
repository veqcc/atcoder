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

    int n;
    cin >> n;

    queue<int> ready;
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
        ready.push(i);
    }

    vector<int> ptr(n);
    vector<vector<bool>> state(n, vector<bool>(n));
    int ans = 0;
    while (!ready.empty()) {
        ans++;
        queue<int> next_ready;
        while (!ready.empty()) {
            int q = ready.front();
            ready.pop();
            int peer = A[q][ptr[q]];
            state[q][peer] = true;
            if (state[peer][q]) {
                ptr[q]++;
                ptr[peer]++;
                if (ptr[q] < n - 1) next_ready.push(q);
                if (ptr[peer] < n - 1) next_ready.push(peer);
            }
        }

        while (!next_ready.empty()) {
            ready.push(next_ready.front());
            next_ready.pop();
        }
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (ptr[i] != n-1) {
            ok = false;
            break;
        }
    }

    cout << (ok ? ans : -1) << '\n';
    return 0;
}