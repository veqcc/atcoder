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

    string s, ret = "First";
    cin >> s;
    int len = s.length();


    if (s[0] == s[len - 1]) {
        if (len % 2 == 1) {
            ret = "Second";
        }
    } else {
        if (len % 2 == 0) {
            ret = "Second";
        }
    }

    cout << ret << "\n";
    return 0;
}