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
    int n, A[3];
    cin >> n >> A[0] >> A[1] >> A[2];

    int l[n];
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    int ans = 1 << 30;
    for (int i = 0; i < (1 << (2 * n)); i++) {
        vector <int> use[4];
        int t = i;
        for (int j = 0; j < n; j++) {
            use[t % 4].push_back(l[j]);
            t /= 4;
        }

        int ret = 0;
        for (int j = 0; j < 3; j++) {
            if (use[j].size() == 0) {
                ret = 1 << 30;
                break;
            }

            int mp = 10 * (use[j].size() - 1);
            int sm = 0;
            for (int k : use[j]) {
                sm += k;
            }

            mp += abs(sm - A[j]);
            ret += mp;
        }

        ans = min(ans, ret);
    }

    cout << ans << "\n";
    return 0;
}
