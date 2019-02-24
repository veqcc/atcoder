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
    string a, b, c;
    cin >> n >> a >> b >> c;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && b[i] == c[i]) {
            continue;
        } else if (a[i] == b[i] || b[i] == c[i] || c[i] == a[i]) {
            ans++;
        } else {
            ans += 2;
        }
    }

    cout << ans << "\n";
    return 0;
}