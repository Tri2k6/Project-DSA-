#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <typename T, typename Compare = less<T>>

class PriorityQueue {
private:
    vector <T> heap;
    Compare comp;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (!comp(heap[index], heap[parent])) break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (2 * index + 1 < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int best = index;

            if (left < size && comp(heap[left], heap[best]))
                best = left;
            if (right < size && comp(heap[right], heap[best]))
                best = right;

            if (best == index) break;
            swap(heap[index], heap[best]);
            index = best;
        }
    }

public:
    bool isEmpty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }

    void push(const T& value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        if (isEmpty()) throw std::runtime_error("PriorityQueue is empty");
        T val = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return val;
    }

    const T& top() const {
        if(isEmpty()) throw std::runtime_error("PriorityQueue is empty");
        return heap[0];
    }

    void remove(int value)
    {
        int index = 0;
        while (index < heap.size() && heap[index] != value)
            index++;

        if (index < heap.size())
        {
            swap(heap[index], heap[heap.size() - 1]);
            heap.pop_back();
            heapifyDown(0);
            std::cout << "Value deleted\n";
        }
        else
            std::cout << "Value doesn't exist in heap\n";
    }

    void buildHeap(const vector<T>& items)  {
        heap = items;
        int n = heap.size();
        for (int i  = n / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    void clear() {
        heap.clear();
    }

    void print() const {
        for (const T& val : heap) {
            cout << val << " ";
        }
        cout << "\n";
    }
};
