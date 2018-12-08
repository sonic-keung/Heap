#include <iostream>
#include "heap.hpp"

int main() {
    vector<int> addToHeap = {5, 8, 12, 3, 16, 18};
    make_heap(addToHeap.begin(), addToHeap.end());

    Heap<int> &heap = Heap<int>::instance();
    Heap<int> &heap2 = Heap<int>::instance();

    heap.push(1);
    heap2.push(2);

    cout << "First Heap: " <<  heap << endl;
    cout << "Second Heap: " << heap2 << endl;

    cout << "Heap: " << endl;
    for (int &x : addToHeap) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Heap size: " << endl;
    cout << heap.size() << endl;

    heap.push(22);
    cout << "New heap after pushing 22: " << endl;
    cout << heap << endl;

    cout << "Heap size: " << endl;
    cout << heap.size() << endl;

    cout << "After pop: " << endl;
    heap.pop();
    cout << heap << endl;

    heap.clear();
    cout << "Is empty: " << heap.is_empty() << endl;
    cout << "Size: " << heap.size() << endl;
    cout << endl;

    return 0;
}