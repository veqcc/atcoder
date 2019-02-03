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
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int ans = 0;
    for (int i = 0; i < 100; i++) {
        int water = false;
        for (int j = 0; j < n; j++) {
            if (h[j] > 0) {
                water = true;
                h[j]--;
            } else {
                if (water) {
                    ans++;
                    water = false;
                }
            }
        }
        if (water) ans++;
    }

    cout << ans << "\n";
    return 0;
}