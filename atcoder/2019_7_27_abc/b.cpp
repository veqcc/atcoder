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

    vector <int> p(n);
    int c = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] != i + 1) c++;
    }

    if (c == 0 || c == 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}