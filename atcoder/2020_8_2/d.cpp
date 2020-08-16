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
    int n;
    string s;
    cin >> n >> s;

    int red = 0;
    for (char c : s) red += c == 'R';

    int ans = 0;
    for (int i = 0; i < red; i++) ans += s[i] == 'W';

    cout << ans << endl;
    return 0;
}