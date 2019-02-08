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
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int b, k;
    cin >> b >> k;
    int sm = 0;
    int a[k];
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        sm += a[i];
    }

    if (b % 2 == 0) {
        if (a[k-1] % 2 == 0) {
            cout << "even\n";
        } else {
            cout << "odd\n";
        }
    } else {
        if (sm % 2 == 0) {
            cout << "even\n";
        } else {
            cout << "odd\n";
        }
    }

    return 0;
}