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

    int n, a, b;
    cin >> n >> a >> b;
    int c1=0, c2=0, c3=0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p <= a) c1++;
        else if (p <= b) c2++;
        else c3++;
    }

    cout << min(c1, min(c2, c3)) << "\n";
    return 0;
}