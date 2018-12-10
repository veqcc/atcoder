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
    int sm = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        sm += p;
        mx = max(mx, p);
    }

    cout << sm - mx/2 << "\n";
    return 0;
}