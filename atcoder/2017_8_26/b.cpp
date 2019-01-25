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
    ll len = s.size();
    ll alph[26];
    fill(alph, alph+26, 0);
    for (int i = 0; i < len; i++) {
        alph[s[i] - 'a']++;
    }

    ll ret = len * (len - 1) / 2 + 1;
    for (int i = 0; i < 26; i++) {
        ret -= alph[i] * (alph[i] - 1) / 2;
    }

    cout << ret << "\n";
    return 0;
}