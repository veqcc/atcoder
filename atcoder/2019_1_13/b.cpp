#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

const string keyence = "keyence";

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    bool ret = false;
    for (int i = 0; i < 7; i++) {
        int p = 0;
        bool ans = true;

        for (int j = 0; j < i; j++) {
            if (s[j] != keyence[p]) {
                ans = false;
            }
            p++;
        }

        for (int j = s.size() + i - 7; j < s.size(); j++) {
            if (s[j] != keyence[p]) {
                ans = false;
            }
            p++;
        }

        if (ans) {
            ret = ans;
        }
    }

    if (ret) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}