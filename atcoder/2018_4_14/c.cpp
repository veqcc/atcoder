#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x[n];
    int sort_x[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        sort_x[i] = x[i];
    }

    sort(sort_x, sort_x + n);

    int a = sort_x[n/2 - 1];
    int b = sort_x[n/2];

    for (int i = 0; i < n; i++) {
        if (x[i] < b) {
            cout << b << endl;
        }
        else {
            cout << a << endl;
        }
    }

    return 0;
}