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

    int x = 0; // 010101...
    int y = 0; // 101010...
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (i % 2 == 0) {
                y++;
            } else {
                x++;
            }
        } else {
            if (i % 2 == 0) {
                x++;
            } else {
                y++;
            }
        }
    }

    cout << min(x, y) << "\n";
    return 0;
}