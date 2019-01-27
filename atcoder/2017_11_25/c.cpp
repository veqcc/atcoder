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
    int count[13];
    fill(count, count+13, 0);
    count[0] = 1;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        count[d]++;
    }

    int ans = 0;
    for (int i = 0; i < 13; i++) {
        if (count[i] > 1 + (i != 0 && i != 12)) {
            ans = 24;
        }
    }

    for (int i = 0; i < (1 << 11); i++) {
        vector <int> d;
        d.push_back(0);
        d.push_back(24);
        if (count[12] == 1) {
            d.push_back(12);
        }

        for (int j = 1; j < 12; j++) {
            if (count[j] == 0) {
                continue;
            } else if (count[j] == 2) {
                d.push_back(j);
                d.push_back(24 - j);
            } else {
                if ((i >> (j-1)) & 1) {
                    d.push_back(j);
                } else {
                    d.push_back(24 - j);
                }
            }
        }

        int mn = 24;
        for (int j = 0; j < d.size(); j++) {
            for (int k = j+1; k < d.size(); k++) {
                mn = min(mn, abs(d[j] - d[k]));
            }
        }

        ans = max(ans, mn);
    }

    cout << ans % 24 << "\n";
    return 0;
}
