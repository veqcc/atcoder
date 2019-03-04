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

int n, k, a[1005], start_time[1005];
vector <int> cnt;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    priority_queue < int, vector<int>, greater<int> > q;
    for (int i = 0; i < k; i++) {
        q.push(a[i]);
        start_time[i] = 0;
    }

    int idx = k;
    while (q.size()) {
        int finish = q.top(); q.pop();
        cnt.push_back(finish);
        if (idx < n) {
            start_time[idx] = finish;
            q.push(finish + a[idx]);
            idx++;
        }
    }

    int mx = cnt[n-1];
    int percent[mx+1];
    fill(percent, percent + mx + 1, 0);
    for (int i = 0; i < n; i++) {
        percent[cnt[i]] = (1000 * (i + 1) / n + 5) / 10;
    }

    for (int i = 1; i <= mx; i++) {
        if (percent[i] == 0) percent[i] = percent[i-1];
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= a[i]; j++) {
            if (percent[start_time[i] + j - 1] == j) {
                ret++;
                break;
            }
        }
    }

    cout << ret << "\n";
    return 0;
}