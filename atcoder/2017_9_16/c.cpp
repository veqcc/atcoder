#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    bool water[30];
    fill(water, water+30, false);
    water[0] = true;
    for (int i = 0; i < 30; i++) {
        if (water[i]) {
            if (i+A < 30) water[i+A] = true;
            if (i+B < 30) water[i+B] = true;
        }
    }

    bool sugar[3000];
    fill(sugar, sugar+3000, false);
    sugar[0] = true;
    for (int i = 0; i < 3000; i++) {
        if (sugar[i]) {
            if (i+C < 3000) sugar[i+C] = true;
            if (i+D < 3000) sugar[i+D] = true;
        }
    }

    int w=A, s=0;
    double concentration=0.0;
    for (int i = 1; i < 30; i++) {
        for (int j = 0; j < 3000; j++) {
            if (water[i] && sugar[j]) {
                if (i*100+j <= F && i*E >= j && concentration < (double)100*j/(double)(i*100+j)) {
                    w = i;
                    s = j;
                    concentration = (double)100*j/(double)(i*100+j);
                }
            }
        }
    }

    cout << w*100+s << " " << s << endl;
    return 0;
}