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

    for (int i = 1; i <= n; i++) {
        string ret = "";
        if (i % 2 == 0) ret += 'a';
        if (i % 3 == 0) ret += 'b';
        if (i % 4 == 0) ret += 'c';
        if (i % 5 == 0) ret += 'd';
        if (i % 6 == 0) ret += 'e';

        if (ret == "") {
            ret += to_string(i);
        }

        cout << ret << '\n';
    }

    return 0;
}