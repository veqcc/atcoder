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
    int n;
    cin >> n;

    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        double x;
        string u;
        cin >> x >> u;

        if (u == "JPY") {
            ans += x;
        } else {
            ans += x * 380000.0;
        }
    }

    cout << fixed << setprecision(8) << ans << "\n";
    return 0;
}