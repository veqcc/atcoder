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
    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        int sz = s.size();

        int idx = 0;
        for (; idx + 3 < sz; idx++) {
            if (s.substr(idx, 4) == "okyo") {
                break;
            }
        }

        if (idx + 3 >= sz) {
            cout << "No\n";
            continue;
        }

        for (; idx + 2 < sz; idx++) {
            if (s.substr(idx, 3) == "ech") {
                break;
            }
        }

        if (idx + 2 >= sz) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";
    }

    return 0;
}