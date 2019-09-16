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

    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 1 && s[i] == 'R') {
            cout << "No" << "\n";
            return 0;
        }
        if (i % 2 == 0 && s[i] == 'L') {
            cout << "No" << "\n";
            return 0;
        }
    }

    cout << "Yes" << "\n";
    return 0;
}