#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

ll n, a, s1, s2, c1, c2;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s1 += a;
        s2 += a;
        if (i % 2) {
            if (s1 <= 0) c1 += 1 - s1, s1 = 1;
            if (s2 >= 0) c2 += 1 + s2, s2 = -1;
        }
        else {
            if (s1 >= 0) c1 += 1 + s1, s1 = -1;
            if (s2 <= 0) c2 += 1 - s2, s2 = 1;
        }
    }

    cout << min(c1, c2) << endl;
    return 0;
}