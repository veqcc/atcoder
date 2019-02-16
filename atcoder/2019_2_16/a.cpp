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
    int a,b;
    cin >> a >> b;

    if (b % a == 0) {
        cout << a + b << "\n";
    } else {
        cout << b - a << "\n";
    }

    return 0;
}