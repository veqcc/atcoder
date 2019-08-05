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

    if (n < 10) {
        cout << n << '\n';
    } else if (n < 100) {
        cout << 9 << '\n';
    } else if (n < 1000) {
        cout << 9 + (n - 99) << "\n";
    } else if (n < 10000) {
        cout << 9 + 900 << "\n";
    } else if (n < 100000) {
        cout << 9 + 900 + (n - 9999) << "\n";
    } else {
        cout << 9 + 900 + 90000 << "\n";
    }

    return 0;
}