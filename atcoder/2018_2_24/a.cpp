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

// 約数のvectorを返す 重複なし O(√n)
vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) ret.push_back(n);
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, a;
    cin >> n >> m;

    map <int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a;
        vector <int> div = divisor(a);
        int sz = div.size();
        for (int j = 1; j < (1 << sz); j++) {
            int tmp = 1;
            for (int k = 0; k < sz; k++) if (j & (1 << k)) tmp *= div[k];
            mp[tmp] += 1;
        }
    }

    for (int i = 1; i <= m; i++) {
        vector <int> div = divisor(i);
        int sz = div.size();
        int ans = 0;
        for (int j = 1; j < (1 << sz); j++) {
            int num = 0;
            int tmp = 1;
            for (int k = 0; k < sz; k++) {
                if (j & (1 << k)) {
                    num++;
                    tmp *= div[k];
                }
            }
            if (num % 2 == 1) ans += mp[tmp];
            else ans -= mp[tmp];
        }
        cout << n - ans << "\n";
    }

    return 0;
}