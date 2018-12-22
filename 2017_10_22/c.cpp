#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int bg=0, ed=s.length()-1, ans=0;
    while (ed - bg > 0) {
        if (s[bg] == s[ed]) {
            bg++; ed--;
        } else if (s[bg] == 'x') {
            bg++; ans++;
        } else if (s[ed] == 'x') {
            ed--; ans++;
        } else {
            ans = -1; break;
        }
    }

    cout << ans << "\n";
    return 0;
}