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
typedef pair <int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    if (k > (n - 1) * (n - 2) / 2) {
        cout << -1 << '\n';
        return 0;
    }

    int diff = (n - 1) * (n - 2) / 2 - k;

    cout << n - 1 + diff << '\n';

    for (int i = 2; i <= n; i++) {
        cout << 1 << " " << i << '\n';
    }

    vector <P> vec;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            vec.push_back(P(i, j));
        }
    }

    int idx = 0;
    while (diff) {
        cout << vec[idx].first << " " << vec[idx].second << "\n";
        idx++;
        diff--;
    }

    return 0;
}