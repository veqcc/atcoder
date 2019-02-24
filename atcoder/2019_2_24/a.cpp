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
    string s;
    cin >> s;

    int month = (s[5] - '0') * 10 + s[6] - '0';

    if (month <= 4) {
        cout << "Heisei\n";
    } else {
        cout << "TBD\n";
    }

    return 0;
}