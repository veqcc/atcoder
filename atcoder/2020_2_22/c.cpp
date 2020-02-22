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

    vector <int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    int ans = 1e9;
    for (int i = 1; i <= 1000; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += (i - x[j]) * (i - x[j]);
        }
        ans = min(ans, sum);
    }

    cout << ans << "\n";
    return 0;
}