#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    string ans;
    if (a > 0) ans = "Positive";
    else if (b < 0) {
        if ((b-a)%2 == 1) ans = "Positive";
        else ans = "Negative";
    }
    else ans = "Zero";

    cout << ans << "\n";
    return 0;
}