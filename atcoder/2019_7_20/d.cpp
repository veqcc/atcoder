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

// 約数のvectorを返す
vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n / i) ret.push_back(n / i);
        }
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector <int> ans;
    for (int i = n; i > 0; i--) {
        if (a[i] % 2 == 1) {
            ans.push_back(i);
            vector <int> div = divisor(i);
            for (int d : div) a[d]++;
        }
    }

    cout << ans.size() << "\n";
    for (int ret : ans) cout << ret << " ";

    return 0;
}