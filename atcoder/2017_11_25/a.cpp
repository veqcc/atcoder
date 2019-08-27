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

    string akihabara = "AKIHABARA";

    int pos = 0;
    for (int i = 0; i < s.size();) {
        if (pos >= akihabara.size()) {
            cout << "NO\n";
            return 0;
        }

        if (s[i] == akihabara[pos]) {
            pos++;
            i++;
        } else if (akihabara[pos] == 'A') {
            pos++;
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    if (pos < akihabara.size() - 1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES" << "\n";
    return 0;
}