#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    ll n;
    cin >> n;
    n %= 9;
    if (n % 2 == 0 && n != 8) {
        cout << "Lose\n";
    } else {
        cout << "Win\n";
    }

    return 0;
}