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

int main() {
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    a--; b--; c--; d--;

    bool ans = true;

    for (int i = b+1; i <= d-1; i++) {
        if (s[i] == '#' && s[i+1] == '#') {
            ans = false;
            break;
        }
    }

    for (int i = a+1; i <= c-1; i++) {
        if (s[i] == '#' && s[i+1] == '#') {
            ans = false;
            break;
        }
    }

    if (c > d) {
        bool flag = false;
        for (int i = b; i <= d; i++) {
            if (s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') {
                flag = true;
                break;
            }
        }
        if (!flag) ans = false;
    }

    cout << (ans ? "Yes" : "No") << "\n";
    return 0;
}