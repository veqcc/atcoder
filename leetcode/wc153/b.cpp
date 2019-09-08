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

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        map <int, int> mp;
        mp[1] = mp[3] = mp[5] = mp[7] = mp[8] = mp[10] = mp[31] = 31;
        mp[2] = 28;
        mp[4] = mp[6] = mp[9] = mp[11] = 30;

        string d[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        // 1/1/1971: Friday
        int cur = 5;

        // leap yearは1972
        for (int y = 1971; y < year; y++) {
            if (y % 4 == 0) {
                cur = (cur + 366) % 7;
            } else {
                cur = (cur + 365) % 7;
            }
        }

        for (int m = 1; m < month; m++) {
            if (m == 2 && year % 4 == 0) {
                cur = (cur + 29) % 7;
            } else {
                cur = (cur + mp[m]) % 7;
            }
        }

        cur = (cur + day - 1) % 7;

        return d[cur];
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int d, m, y;
    cin >> d >> m >> y;

    Solution s;

    cout << s.dayOfTheWeek(d, m, y) << "\n";
    return 0;
}