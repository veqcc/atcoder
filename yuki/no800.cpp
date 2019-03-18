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

    int n, d;
    cin >> n >> d;

    vector <int> vec(2*n*n+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            vec[i*i + j*j]++;
        }
    }

    int ans = 0;
    for (int z = 1; z <= n; z++) {
        for (int w = 1; w <= n; w++) {
            int E = w*w + d - z*z;
            if (E > 1 && E <= 2*n*n) ans += vec[E];
        }
    }

    cout << ans << '\n';
    return 0;
}