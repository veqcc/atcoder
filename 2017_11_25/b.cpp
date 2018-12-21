#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int a=0, b=0, c=0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') a++;
        if (s[i] == 'b') b++;
        if (s[i] == 'c') c++;
    }

    if (abs(a-b)<=1 && abs(b-c)<=1 && abs(c-a)<=1) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}