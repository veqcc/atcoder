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

    char c;
    cin >> c;

    if (c == 'A') {
        cout << "T\n";
    } else if (c == 'C') {
        cout << "G\n";
    } else if (c == 'G') {
        cout << "C\n";
    } else {
        cout << "A\n";
    }

    return 0;
}