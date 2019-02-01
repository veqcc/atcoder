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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    if (n < 3) {
        cout << 0 << "\n";
        return 0;
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n-1; j++) {
            if (s[i][j] == 'X' &&
                s[i-1][j-1] == 'X' &&
                s[i-1][j+1] == 'X' &&
                s[i+1][j-1] == 'X' &&
                s[i+1][j+1] == 'X') {
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}