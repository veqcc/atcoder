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

    if (s[0] == s[1] && s[2] == s[3] && s[0] != s[2]) {
        cout << "Yes\n";
    } else if (s[0] == s[2] && s[1] == s[3] && s[0] != s[1]) {
        cout << "Yes\n";
    } else if (s[0] == s[3] && s[1] == s[2] && s[0] != s[1]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}