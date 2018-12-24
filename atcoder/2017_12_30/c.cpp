#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int c[n-1], s[n-1], f[n-1];
    for (int i = 0; i < n-1; i++) {
        cin >> c[i] >> s[i] >> f[i];
    }

    for (int i = 0; i < n; i++) {
        int time = 0;
        for (int j = i; j < n-1; j++) {
            if (time <= s[j]) {
                time = s[j] + c[j];
            } else if ((time-s[j]) % f[j] == 0) {
                time += c[j];
            } else {
                time += f[j] - ((time-s[j]) % f[j]) + c[j];
            }
        }

        cout << time << endl;
    }

    return 0;
}