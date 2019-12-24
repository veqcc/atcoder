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

    int n, k;
    string s;
    cin >> n >> k >> s;

    string head = s.substr(0, k);

    bool is_small = false;
    for (int i = k; i < n; i++) {
        if (s[i] > head[i % k]) {
            is_small = true;
            break;
        } else if (s[i] < head[i % k]) {
            break;
        }
    }

    if (is_small) {
        int cur = k - 1;
        while (true) {
            if (head[cur] == '9') {
                head[cur] = '0';
                cur--;
            } else {
                head[cur]++;
                break;
            }
        }
    }

    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << head[i % k];
    }

    cout << "\n";
    return 0;
}