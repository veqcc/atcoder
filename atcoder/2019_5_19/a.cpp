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
    int n, k;
    string s;
    cin >> n >> k >> s;
    k--;

    if (s[k] == 'A') s[k] = 'a';
    if (s[k] == 'B') s[k] = 'b';
    if (s[k] == 'C') s[k] = 'c';

    cout << s << "\n";
    return 0;
}