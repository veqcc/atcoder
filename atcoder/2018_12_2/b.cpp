#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int ans = 100000;
    for (int i = 0; i < s.length()-2; i++) {
        int tmp = 0;
        tmp += (s.at(i) - '0') * 100;
        tmp += (s.at(i+1) - '0') * 10;
        tmp += (s.at(i+2) - '0') * 1;

        ans = min(ans, abs(753-tmp));
    }

    cout << ans << "\n";
    return 0;
}