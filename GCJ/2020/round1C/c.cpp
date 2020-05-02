#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
typedef pair <int, char> P;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n, d;
        cin >> n >> d;

        vector <double> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int ans = 100;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= d; j++) {
                // i番目の大きさのものをj当分した大きさをd個作る最低コスト
                if (i && a[i] == a[i - 1]) continue;

                int cur = 0, sum = 0;
                double sz = a[i] / j;

                for (int k = 0; k < n; k++) {
                    ll c = a[k] / sz;
                    if (abs(c * sz - a[k]) < 1e-8) {
                        if (sum + c <= d) {
                            sum += c;
                            cur += c - 1;
                        } else {
                            cur += d - sum;
                            sum = d;
                            break;
                        }
                    }
                }

                for (int k = 0; k < n; k++) {
                    ll c = a[k] / sz;
                    if (abs(c * sz - a[k]) >= 1e-8) {
                        if (sum + c <= d) {
                            sum += c;
                            cur += c;
                        } else {
                            cur += d - sum;
                            sum = d;
                            break;
                        }
                    }
                }

                if (sum == d) ans = min(ans, cur);
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}