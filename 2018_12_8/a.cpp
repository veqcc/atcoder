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

    int n;
    cin >> n;

    string s;
    if (n == 25) {
        s = "Christmas";
    } else if (n == 24) {
        s = "Christmas Eve";
    } else if (n == 23) {
        s = "Christmas Eve Eve";
    } else if (n == 22) {
        s = "Christmas Eve Eve Eve";
    }

    cout << s << "\n";
    return 0;
}