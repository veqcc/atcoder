#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int MAX_N=100000;

int heap[MAX_N], sz=0;

void push(int x) {
    int i = sz++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= x) {
            break;
        }
        heap[i] = heap[parent];
        i = parent;
    }
    heap[i] = x;
}

int pop() {
    int ret = heap[0];
    int x = heap[--sz];
    int i = 0;
    while (i * 2 + 1 < sz) {
        int a = i * 2 + 1; // left child
        int b = i * 2 + 2; // right child
        if (b < sz && heap[b] < heap[a]) {
            a = b;
        }
        if (heap[a] >= x) {
            break;
        }
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}

int main() {
    push(3);
    push(2);
    push(5);

    cout << pop() << endl; // 2
    return 0;
}