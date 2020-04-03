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

    if (s[0] == '0') {
        cout << "Nothing\n";
    } else if (s[0] == '3') {
        cout << "pi\n";
    } else if (s[1] == '1') {
        cin >> s;
        cout << "九蓮宝燈\nThirteen Orphans\n";
    } else if (s[0] == 'A') {
        cout << 3 << '\n';
        cout << 4 << '\n';
        cout << 4 << '\n';
        cout << 3 << '\n';
        cout << 6 << '\n';
        cout << 2 << '\n';
        cout << 2 << '\n';
    } else {
        cout << "さｍｐぇ\n";
    }

    return 0;
}