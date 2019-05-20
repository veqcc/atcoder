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

    int pre = 10 * (s[0] - '0') + (s[1] - '0');
    int pos = 10 * (s[2] - '0') + (s[3] - '0');

    if (pre == 0 || pre > 12) {
        // pre は year
        if (pos > 0 && pos < 13) {
            cout << "YYMM\n";
        } else {
            cout << "NA\n";
        }
    } else {
        if (pos > 0 && pos < 13) {
            cout << "AMBIGUOUS\n";
        } else {
            cout << "MMYY\n";
        }
    }

    return 0;
}