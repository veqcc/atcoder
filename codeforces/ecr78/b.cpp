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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int a, b;
        cin >> a >> b;

        int diff = abs(a - b);

        int cnt = 0;
        int sum = 0;
        while (sum < diff) {
            cnt++;
            sum += cnt;
        }

        if (sum == diff) {
            cout << cnt << '\n';
        } else {
            if ((sum - diff) % 2 == 0) {
                cout << cnt << '\n';
            } else {
                cnt++;
                sum += cnt;
                if ((sum - diff) % 2 == 0) {
                    cout << cnt << '\n';
                } else {
                    cout << cnt + 1 << '\n';
                }
            }
        }
    }

    return 0;
}