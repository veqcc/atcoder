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

    int n;
    string s;
    cin >> n >> s;

    int mn = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            sum++;
        } else {
            sum--;
        }
        mn = min(mn, sum);
    }

    if (sum != 0 || mn < -1) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    return 0;
}