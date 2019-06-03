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
    string s;
    cin >> s;
    int n = s.size();

    ll a = 0, ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'A') {
            a++;
        } else if (s[i] == 'B' && s[i + 1] == 'C') {
            ans += a;
            i++;
        } else {
            a = 0;
        }
    }

    cout << ans << "\n";
    return 0;
}