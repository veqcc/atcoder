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
    cin >> n;

    vector<int> red, blue;
    for (int i = 0; i < n; i++) {
        int x;
        char c;
        cin >> x >> c;

        if (c == 'R') {
            red.push_back(x);
        } else {
            blue.push_back(x);
        }
    }

    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());

    for (int x : red) cout << x << '\n';
    for (int x : blue) cout << x << '\n';

    return 0;
}