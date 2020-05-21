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

    int k;
    string s;
    cin >> k >> s;

    if (s.size() <= k) {
        cout << s << endl;
    } else {
        cout << s.substr(0, k) << "..." << endl;
    }

    return 0;
}