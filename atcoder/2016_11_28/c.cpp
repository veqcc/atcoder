#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n], x = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x ^= a[i];
        a[i] ^= a[i] - 1;
    }

    sort(a, a+n, greater<int>());

    int ret = 0;
    for (int i = 0; i < n; i++) {
        if ((x ^ a[i]) < x) {
            x ^= a[i];
            ret++;
        }
    }

    cout << (x > 0 ? -1 : ret) << "\n";
    return 0;
}
