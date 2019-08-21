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

    vector <string> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        sort(vec[i].begin(), vec[i].end());
    }

    sort(vec.begin(), vec.end());

    ll count = 1;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (vec[i] != vec[i - 1]) {
            ans += count * (count - 1) / 2LL;
            count = 1;
        } else {
            count++;
        }
    }

    ans += count * (count - 1) / 2LL;
    cout << ans << "\n";
    return 0;
}