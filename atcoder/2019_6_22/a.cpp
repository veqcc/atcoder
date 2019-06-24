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

    bool good = true;
    for (int i = 0; i < 3; i++) {
        if (s[i] == s[i+1]) {
            good = false;
        }
    }

    cout << (good ? "Good" : "Bad") << "\n";
    return 0;
}