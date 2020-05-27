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
    int n, d;
    string s;
    cin >> n >> d >> s;

    int cnt = 1, cur = 0;
    while (cur < n - d - 1) {
        bool possible = false;
        for (int j = d; j; j--) {
            if (s[cur + j] == '1') {
                cur += j;
                cnt++;
                possible = true;
                break;
            }
        }
        if (!possible) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << cnt << endl;
    return 0;
}