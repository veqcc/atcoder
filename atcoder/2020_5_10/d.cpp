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
    ll k;
    cin >> n >> k;

    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    int cycle_num;
    vector <int> order(n, -1);

    int cur = 0, ord = 0;
    while (true) {
        if (order[cur] != -1) {
            cycle_num = ord - order[cur];
            break;
        }

        order[cur] = ord++;
        cur = a[cur];
        k--;

        if (k == 0) {
            cout << cur + 1 << endl;
            return 0;
        }
    }

    k %= cycle_num;

    while (k) {
        cur = a[cur];
        k--;
    }

    cout << cur + 1 << "\n";
    return 0;
}