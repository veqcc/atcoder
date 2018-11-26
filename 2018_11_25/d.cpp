#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;

    char c = s[0];
    int count = 1;
    for (int i = 1; i < s.length(); i++) {
        if (c - s[i] >= 0) {
            c = s[i];
            count++;
        }
    }

    cout << count << endl;
    return 0;
}