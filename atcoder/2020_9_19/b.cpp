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
    cin >> n;

    bool zoro = false;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cur++;
            if (cur == 3) zoro = true;
        } else {
            cur = 0;
        }
    }

    cout << (zoro ? "Yes" : "No") << endl;
    return 0;
}