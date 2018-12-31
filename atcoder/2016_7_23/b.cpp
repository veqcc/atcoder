#include <algorithm>
#include <iostream>
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

    int n, l;
    cin >> n >> l;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s, s+n);

    for (int i = 0; i < n; i++) {
        cout << s[i];
    }

    return 0;
}