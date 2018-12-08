#include <iostream>
#include <vector>
#include <algorithm>

/*
 * Using singleton pattern
 */

using namespace std;
template<typename T>
class Heap {
    vector<T> heap;
    Heap() {}

    void heapify() {
        make_heap(heap.begin(), heap.end());
    };

public:
    // disable copy constructor
    Heap(const Heap&) = delete;

    // disable assignment operator
    void operator=(Heap const& h) = delete;

    // return the instance of the class
    static Heap& instance() {
        static Heap heapInstance;
        return heapInstance;
    }

    // push element back to heap
    void push(T element) {
        heap.push_back(element);
        heapify();
    };

    // pop the element from the head
    T pop() {
        T elements;
        elements = heap.front();
        heap.pop_back();
        pop_heap(heap.begin(), heap.end());
        heapify();
        return elements;
    };

    // return the size of heap
    int size() {
        return heap.size();
    };

    // check if heap is empty
    bool is_empty() {
        if(heap.size() == 0) {
            return true;
        }
        return false;
    };

    // clear the heap
    void clear() {
        heap.clear();
    };

    // display heap
    friend ostream& operator << (ostream &os, const Heap &heap) {
        for (unsigned i = 0; i< heap.heap.size(); i++) {
            std::cout << ' ' << heap.heap[i];
        }
        std::cout << '\n';
        return os;
    };

    template<typename Container>
    //A constructor that accepts any STL sequence of elements and copies to the heap
    explicit Heap(Container c) {
        for (auto itr = c.begin(); itr != c.end(); ++itr) {
            heap.push_back(*itr);
        }
        heapify();
    };
};