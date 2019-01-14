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

    int n1=0, n9=0, n7=0, n4=0;
    for (int i = 0; i < 4; i++) {
        int n;
        cin >> n;
        if (n == 1) n1++;
        if (n == 9) n9++;
        if (n == 7) n7++;
        if (n == 4) n4++;
    }

    if (n1 * n9 * n7 * n4 == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}