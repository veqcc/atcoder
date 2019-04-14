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

    if (n % 2 == 1 || s[0] == ')' || s[n-1] == '(') {
        cout << ":(\n";
        return 0;
    }

    int l = 0, r = 0;
    for (int i = 1; i < n-1; i++) {
        if (s[i] == '(') l++;
        if (s[i] == ')') r++;
    }

    int c = 0;
    for (int i = 1; i < n-1; i++) {
        if (s[i] == ')') {
            c--;
            if (c < 0) {
                cout << ":(\n";
                return 0;
            }
        } else {
            c++;
        }
    }

    c = 0;
    for (int i = n-2; i > 0; i--) {
        if (s[i] == '(') {
            c--;
            if (c < 0) {
                cout << ":(\n";
                return 0;
            }
        } else {
            c++;
        }
    }

    int mx = (n-2) / 2;

    cout << '(';
    for (int i = 1; i < n-1; i++) {
        if (s[i] == '?') {
            if (l < mx) {
                cout << '(';
                l++;
            } else {
                cout << ')';
            }
        } else {
            cout << s[i];
        }
    }
    cout << ')';

    return 0;
}