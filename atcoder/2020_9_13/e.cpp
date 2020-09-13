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
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x[i] = a + b;
        y[i] = a - b;
    }

    cout << max(
            *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end()),
            *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end())
            ) << endl;
    return 0;
}