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
    int n;
    cin >> n;

    int a[n];
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int len = 0, tmp = 0;
    bool aj = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == mx) {
            if (aj) {
                tmp++;
                len = max(len, tmp);
            } else {
                tmp = 1;
                len = max(len, tmp);
                aj = true;
            }
        } else {
            aj = false;
        }
    }

    cout << len << "\n";
    return 0;
}