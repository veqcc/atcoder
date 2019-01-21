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
    string s;
    cin >> n >> s;

    int mx = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '>') {
            count++;
            mx = max(mx, count);
        } else {
            count = 0;
        }
    }

    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            count = 0;
            ans += 1.0;
        } else {
            ans += 1.0 / (double)(count+2);
            count++;
        }
    }

    ans -= 1.0;
    ans += 1.0 / (double)(mx + 2);

    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}