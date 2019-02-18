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

    int len = s.size();
    bool possible = false;
    char prev = s[0];
    for (int i = 1; i < len; i++) {
        if (len % 2 == 1 && i == len / 2) continue;
        if (s[i] != prev) possible = true;
    }

    if (!possible) {
        cout << "Impossible\n";
        return 0;
    }

    for (int i = 1; i <= len / 2; i++) {
        string new_s = s.substr(i, len-1) + s.substr(0, i);
        if (new_s == s) continue;

        bool palindrome = true;
        for (int j = 0; j < len / 2; j++) {
            if (new_s[j] != new_s[len - j - 1]) palindrome = false;
        }

        if (palindrome) {
            cout << "1\n";
            return 0;
        }
    }

    cout << "2\n";
    return 0;
}