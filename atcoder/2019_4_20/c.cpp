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

    int n;
    string s;
    cin >> n >> s;

    vector <int> white(n+1, 0);
    vector <int> black(n+1, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') black[i+1]++;
        black[i+1] += black[i];
    }

    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '.') white[i]++;
        white[i] += white[i+1];
    }

    int ans = n;
    for (int k = 0; k <= n; k++) {
        ans = min(ans, black[k] + white[k]);
    }

    cout << ans << "\n";
    return 0;
}