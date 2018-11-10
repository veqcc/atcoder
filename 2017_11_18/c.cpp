#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    string abcd;
    cin >> abcd;

    int a = abcd.at(0) - '0';
    int b = abcd.at(1) - '0';
    int c = abcd.at(2) - '0';
    int d = abcd.at(3) - '0';

    if (a+b+c+d == 7) cout << a << "+" << b << "+" << c << "+" << d << "=" << 7 << endl;
    else if (a+b+c-d == 7) cout << a << "+" << b << "+" << c << "-" << d << "=" << 7 << endl;
    else if (a+b-c+d == 7) cout << a << "+" << b << "-" << c << "+" << d << "=" << 7 << endl;
    else if (a+b-c-d == 7) cout << a << "+" << b << "-" << c << "-" << d << "=" << 7 << endl;
    else if (a-b+c+d == 7) cout << a << "-" << b << "+" << c << "+" << d << "=" << 7 << endl;
    else if (a-b+c-d == 7) cout << a << "-" << b << "+" << c << "-" << d << "=" << 7 << endl;
    else if (a-b-c+d == 7) cout << a << "-" << b << "-" << c << "+" << d << "=" << 7 << endl;
    else if (a-b-c-d == 7) cout << a << "-" << b << "-" << c << "-" << d << "=" << 7 << endl;

    return 0;
}