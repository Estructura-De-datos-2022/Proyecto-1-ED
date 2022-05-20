#ifndef HEAPPRIORITYQUEUE_H
#define HEAPPRIORITYQUEUE_H

#include "PriorityQueue.h"
#include "MaxHeap.h"
#include "KVPair.h"
#include <stdexcept>

using std::runtime_error;

template <typename E>
class HeapPriorityQueue : public PriorityQueue<E> {
private:
    MaxHeap<KVPair<int, E>> elements;
    //int priorities;

public:
    HeapPriorityQueue(int max = DEFAULT_MAX_SIZE) : elements(max) {
    }
    ~HeapPriorityQueue() {}
    void insert(E element, int priority){
        KVPair<int, E> p(priority, element);
        elements.insert(p);
    }
    E min(){
        auto p = elements.first();
        return p.value;
    }
    E removeMin() {
        auto p = elements.removeFirst();
        return p.value;
    }
    bool isEmpty(){
        return elements.getSize() == 0;
    }
    int getSize(){
        return elements.getSize();
    }
};

#endif // HEAPPRIORITYQUEUE_H
