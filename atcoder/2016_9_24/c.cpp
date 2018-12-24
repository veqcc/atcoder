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
    int k;
    cin >> s >> k;

    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == 'a') continue;
        if ('z' - s[i] < k) {
            k  = k - ('z' - s[i]) - 1;
            s[i] = 'a';
        }
    }

    k %= 26;
    s[len-1] = (char)(s[len-1] + k);

    cout << s << "\n";
    return 0;
}