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
typedef pair <int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <P> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i].first >> vec[i].second;

    sort(vec.begin(), vec.end());

    priority_queue<int> q;
    int index = 0;
    int ans = 0;

    for (int day = m - 1; day >= 0; day--) {
        while (index < n && vec[index].first + day <= m) {
            q.push(vec[index].second);
            index++;
        }

        if (!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }

    cout << ans << "\n";
    return 0;
}