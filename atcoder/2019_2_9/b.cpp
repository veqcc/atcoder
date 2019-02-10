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

int c[4];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        c[a]++;
        c[b]++;
    }

    for (int i = 0; i < 4; i++) {
        if (c[i] > 2) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}