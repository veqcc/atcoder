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

    int n;
    cin >> n;

    int one = 0, two = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1) one++;
        if (a == 2) two++;
    }

    if (two == 0) {
        for (int i = 0; i < one; i++) cout << 1 << " ";
    } else {
        if (one == 0) {
            for (int i = 0; i < two; i++) cout << 2 << " ";
        } else {
            cout << 2 << " " << 1 << " ";
            for (int i = 0; i < two - 1; i++) cout << 2 << " ";
            for (int i = 0; i < one - 1; i++) cout << 1 << " ";
        }
    }

    return 0;
}