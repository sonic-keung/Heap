#include <iostream>
#include "heap.hpp"

int main() {
    vector<int> addToHeap = {5, 8, 12, 3, 16, 18};
    Heap<int> heap = Heap<int>::instance();

    heap.push(addToHeap);
    cout << "Heap: " << endl;
    cout << heap << endl;

    cout << "Heap size: " << endl;
    cout << heap.size() << endl;

    heap.push(2);
    cout << "New heap: " << endl;
    cout << heap << endl;

    cout << "After pop: " << endl;
    heap.pop();
    cout << heap << endl;

    heap.clear();
    cout << "Is empty: " << heap.is_empty() << endl;
    cout << "Size: " << heap.size() << endl;
    cout << endl;

    return 0;
}