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
    string s, t;
    cin >> s >> t;

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += s[i] != t[i];
    }

    cout << ans << endl;
    return 0;
}