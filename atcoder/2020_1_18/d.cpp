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
typedef pair <int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ans = MOD;
    for (int i = 0; i < (1 << n); i++) {
        vector <P> even, odd;
        for (int j = 0; j < n; j++) {
            // iのjビット目が立っていたら、j番目の数字はbが使われる
            if (i & (1 << j)) {
                if (j % 2 == 0) {
                    odd.push_back(P(b[j], j));
                } else {
                    even.push_back(P(b[j], j));
                }
            } else {
                if (j % 2 == 0) {
                    even.push_back(P(a[j], j));
                } else {
                    odd.push_back(P(a[j], j));
                }
            }
        }

        int even_size = even.size();
        int odd_size = odd.size();
        if (n % 2 == 0) {
            if (even_size != odd_size) {
                continue;
            }
        } else {
            if (even_size != odd_size + 1) {
                continue;
            }
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        bool check = true;
        int cur = 0;
        vector <int> order(n);
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) {
                // check even
                if (even[j / 2].first < cur) {
                    check = false;
                    break;
                }

                cur = even[j / 2].first;
                order[j] = even[j / 2].second;
            } else {
                // check odd
                if (odd[j / 2].first < cur) {
                    check = false;
                    break;
                }

                cur = odd[j / 2].first;
                order[j] = odd[j / 2].second;
            }
        }

        if (check) {
            vector <int> count(n, 0);

            int tmp = 0;
            for (int j = 0; j < n; j++) {
                int num = order[j];
                tmp += abs(num + count[num] - j);
                for (int k = 0; k < num; k++) count[k]++;
            }

            ans = min(ans, tmp);
        }
    }

    if (ans == MOD) {
        cout << -1 << '\n';
    } else {
        cout << ans << "\n";
    }
    return 0;
}