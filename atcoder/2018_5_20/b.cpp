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
    int n, p;
    cin >> n;
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> p;
        dp[p] = dp[p - 1] + 1;
    }
    cout << n - *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}