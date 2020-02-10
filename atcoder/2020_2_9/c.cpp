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

    bool f = true;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a]++;
        if (mp[a] > 1) {
            f = false;
        }
    }

    if (f) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}