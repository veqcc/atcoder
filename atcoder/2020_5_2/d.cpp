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

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    n = min(n, b - 1);
    cout << a * n / b - a * (n / b) << "\n";
    return 0;
}