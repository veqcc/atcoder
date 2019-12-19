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

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int sm = 0;
        int zero = 0;
        int even = 0;
        for (char c : s) {
            sm += c - '0';
            if (c == '0') zero++;
            if ((c - '0') % 2 == 0) even++;
        }

        if (sm % 3 == 0 && zero && even > 1) {
            cout << "red\n";
        } else {
            cout << "cyan\n";
        }
    }

    return 0;
}