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
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int count = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == s[i] == s[i + 1]) {
            count++;
            if (s[i - 1] == 'R') s[i] = 'G';
            if (s[i - 1] == 'G') s[i] = 'B';
            if (s[i - 1] == 'B') s[i] = 'R';
        } else if (s[i - 1] == s[i]) {
            count++;
            s[i] = 'R';
            if (s[i - 1] != s[i] && s[i] != s[i + 1]) continue;

            s[i] = 'G';
            if (s[i - 1] != s[i] && s[i] != s[i + 1]) continue;

            s[i] = 'B';
            if (s[i - 1] != s[i] && s[i] != s[i + 1]) continue;
        }
    }

    if (s[n - 2] == s[n - 1]) {
        count++;
        if (s[n - 2] == 'R') s[n - 1] = 'G';
        if (s[n - 2] == 'G') s[n - 1] = 'B';
        if (s[n - 2] == 'B') s[n - 1] = 'R';
    }

    cout << count << "\n" << s << "\n";
    return 0;
}