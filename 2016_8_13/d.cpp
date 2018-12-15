#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    int s=-1, g=-1;
    for (int i = 0; i < str.length()-1; i++) {
        if (str[i] == str[i+1]) {
            s = i + 1;
            g = i + 2;
        }
    }

    for (int i = 0; i < str.length() - 2; i++) {
        if (str[i] == str[i+2]) {
            s = i + 1;
            g = i + 3;
        }
    }

    cout << s << " " << g << "\n";
    return 0;
}