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

    map <int, int> mp;
    vector <int> vec;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (mp[a] == 0) vec.push_back(a);
        mp[a]++;
    }

    if (vec.size() == 1) {
        if (mp[0] == n) {
            cout << "Yes\n";
            return 0;
        }
    }

    if (n % 3 != 0) {
        cout << "No\n";
        return 0;
    }

    if (vec.size() == 2) {
        if (mp[0] == n / 3) {
            cout << "Yes\n";
            return 0;
        }
    }

    if (vec.size() == 3) {
        bool f = true;

        if ((vec[0] ^ vec[1] ^ vec[2]) != 0) f = false;
        if (mp[vec[0]] != n / 3) f = false;
        if (mp[vec[1]] != n / 3) f = false;
        if (mp[vec[2]] != n / 3) f = false;

        if (f) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}