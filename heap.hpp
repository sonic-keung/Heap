#include <iostream>
#include <vector>
#include <algorithm>

/*
 * Using singleton pattern
 */

using namespace std;
template <typename T>
class Heap {
    vector<T> heap;
    Heap() {}

    void heapify() {
        make_heap(heap.begin(), heap.end());
    };
public:
    static Heap& instance() {
        static Heap heapInstance;
        return heapInstance;
    }

    void push(T elements) {
        heap.push_back(elements);
        push_heap(heap.begin(), heap.end());
        heapify();
    };

    T pop() {
        T elements;
        elements = heap.front();
        heap.pop_back();
        pop_heap(heap.begin(), heap.end());
        heapify();
        return elements;
    };

    unsigned long size() {
        return heap.size();
    };

    bool is_empty() {
        if(heap.size() == 0) {
            return true;
        }
        return false;
    };

    void clear() {
        heap.clear();
    };

    friend ostream& operator << (ostream &os, const Heap &heap) {
        for (unsigned i = 0; i< heap.heap.size(); i++) {
            std::cout << ' ' << heap.heap[i];
        }
        std::cout << '\n';
        return os;
    };

};