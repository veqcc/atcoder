#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, c;
    cin >> n >> m >> c;

    int b[m];
    for (int i = 0; i < m; i++) cin >> b[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            tmp += a * b[j];
        }
        if (tmp + c > 0) ans++;
    }

    cout << ans << "\n";
    return 0;
}