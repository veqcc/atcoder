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

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector <int> b_count(100005);
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        b_count[b]++;
    }

    vector <int> a_count(100005);
    int mn = n;
    for (int i = 0; i < n; i++) {
        a_count[a[i]]++;
        mn = min(mn, b_count[a[i]] / a_count[a[i]]);
        cout << mn << '\n';
    }

    return 0;
}
