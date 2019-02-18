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

    map <char, int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }

    int palindrome = 0, remain = 0;
    map <char, int> :: iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        palindrome += it->second / 2 * 2;
        remain += it->second % 2;
    }

    if (remain) {
        palindrome++;
        remain--;
    }

    cout << (ll)palindrome * (ll)palindrome + remain << "\n";
    return 0;
}