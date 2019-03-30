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
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') red++;
    }

    if (red > n - red) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}