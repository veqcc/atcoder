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

    if (n % 2 == 0) {
        cout << fixed << setprecision(8) << 1.0 / 2.0 << "\n";
    } else {
        cout << fixed << setprecision(8) << (double)(n / 2 + 1) / (double)n << "\n";
    }

    return 0;
}