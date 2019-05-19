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

    int ans = 0;
    vector <int> cnt(4, 0); // なし、-A, B-, B-A
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int sz = s.size();
        for (int i = 0; i < sz - 1; i++) if (s[i] == 'A' && s[i+1] == 'B') ans++;

        if (s[0] == 'B' && s[sz-1] == 'A') {
            cnt[3]++;
        } else if (s[0] == 'B') {
            cnt[2]++;
        } else if (s[sz-1] == 'A') {
            cnt[1]++;
        } else {
            cnt[0]++;
        }
    }

    ans += min(cnt[1], cnt[2]);
    ans += cnt[3];
    if (cnt[1] == 0 && cnt[2] == 0 && cnt[3] > 0) ans--;

    cout << ans << "\n";
    return 0;
}