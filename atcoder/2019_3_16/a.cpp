#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector <ll> cnt(26, 1);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }

    ll ans = 1LL;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 1) ans = (ans * cnt[i]) % MOD;
    }

    cout << (ans + MOD - 1) % MOD << "\n";
    return 0;
}