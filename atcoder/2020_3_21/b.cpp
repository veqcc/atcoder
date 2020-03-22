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

    int n;
    cin >> n;

    string s;
    cin >> s;

    bool one = false;
    vector <int> vec(n - 1);
    for (int i = 0; i < n - 1; i++) {
        vec[i] = abs(s[i + 1] - s[i]);
        if (vec[i] == 1) one = true;
    }

    int ans = 0;

    int num = 0, num2 = n - 2;
    int den = 0, den2 = 1;

    for (int i = 0; i < n - 1; i++) {
        if (num - den == 0) {
            if (one) vec[i] %= 2;
            ans ^= vec[i];
        }

        int tmp = num2;
        while (tmp && tmp % 2 == 0) {
            num++;
            tmp /= 2;
        }
        num2--;

        tmp = den2;
        while (tmp % 2 == 0) {
            den++;
            tmp /= 2;
        }
        den2++;
    }

    cout << ans << '\n';
    return 0;
}