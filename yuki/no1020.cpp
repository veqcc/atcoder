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

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (int i = 0; i < n - k + 1; i++) cout << s[i + k - 1];
    for (int i = 0; i < k - 1; i++) {
        if ((n - k + 1) % 2 == 0) {
            cout << s[i];
        } else {
            cout << s[k - i - 2];
        }
    }

    cout << endl;
    return 0;
}