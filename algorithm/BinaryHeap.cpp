#include<iostream>
using namespace std;

const int INF = 1 << 30;

class MinHeap {
    int *harr;
    int capacity;
    int heap_size;
public:
    MinHeap(int cap) {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    void MinHeapify(int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < heap_size && harr[l] < harr[smallest]) smallest = l;
        if (r < heap_size && harr[i] < harr[smallest]) smallest = r;
        if (smallest != i) {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    int extractMin() {
        if (heap_size <= 0) {
            return INF;
        } else if (heap_size == 1) {
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        heap_size--;
        harr[0] = harr[heap_size];
        MinHeapify(0);
        return root;
    }

    void decreaseKey(int i, int new_val) {
        harr[i] = new_val;
        int par = (i - 1) / 2;
        while (i != 0 && harr[par] > harr[i]) {
            swap(harr[i], harr[par]);
            i = par;
            par = (i - 1) / 2;
        }
    }

    int getMin() { return harr[0]; }

    void deleteKey(int i) {
        decreaseKey(i, -INF);
        extractMin();
    }

    void insertKey(int k) {
        if (heap_size == capacity) {
            cout << "Overflow\n";
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        int par = (i - 1) / 2;
        while (i != 0 && harr[par] > harr[i]) {
            swap(harr[i], harr[par]);
            i = par;
            par = (i - 1) / 2;
        }
    }
};

int main() {
    MinHeap h(11);

    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();

    return 0;
}