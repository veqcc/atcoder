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

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double A;
        cin >> A;
        sum += 1.0 / A;
    }

    cout << fixed << setprecision(10) << 1.0 / sum << "\n";
    return 0;
}