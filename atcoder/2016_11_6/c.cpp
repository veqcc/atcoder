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

    string s;
    cin >> s;

    int ret = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i+1]) {
            ret++;
        }
    }

    cout << ret << "\n";
    return 0;
}