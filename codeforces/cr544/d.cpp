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
using namespace std;
typedef pair<int, int> P;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int zero = 0, mx = 0;
    int a[n], b[n];
    map <P, int> mp;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] == 0) {
            if (b[i] == 0) zero++;
        } else {
            int g = gcd(a[i], b[i]);
            mx = max(mx, ++mp[P(a[i]/g, b[i]/g)]);
        }
    }

    cout << zero + mx <<  "\n";
    return 0;
}