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

    string s;
    cin >> s;

    int n = s.size();

    bool p = true;

    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            p = false;
        }
    }

    for (int i = 0; i < (n - 1) / 2; i++) {
        if (s[i] != s[(n - 1) / 2 - i - 1]) {
            p = false;
        }
    }

    for (int i = 0; i < (n - 1) / 2; i++) {
        if (s[n / 2 + 1 + i] != s[n - i - 1]) {
            p = false;
        }
    }

    cout << (p ? "Yes" : "No") << "\n";
    return 0;
}