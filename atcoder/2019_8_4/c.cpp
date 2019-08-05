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

    int prev = 0;
    string ans = "Yes";
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        if (h < prev) ans = "No";
        if (h > prev) prev = h - 1;
    }

    cout << ans << '\n';
    return 0;
}