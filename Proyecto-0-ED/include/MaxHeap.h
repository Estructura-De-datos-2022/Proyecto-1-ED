#ifndef MAXHEAP_H
#define MAXHEAP_H
#define DEFAULT_MAX_SIZE 1024

#include <stdexcept>

using std::runtime_error;

template <typename E>
class MaxHeap{
private:
    E *elements;
    int max;
    int size;

    void siftUp(int pos){
        while (pos > 0 && elements[pos] > elements[parent(pos)]){
            swap(pos, parent(pos));
            pos = parent(pos);
        }
    }
    int parent(int pos){
        return (pos - 1) / 2;
    }
    int leftChild(int pos){
        return pos * 2 + 1;
    }
    int rightChild(int pos){
        return pos *2 + 2;
    }
    void swap(int pos1, int pos2) {
        E temp = elements[pos1];
        elements[pos1] = elements[pos2];
        elements[pos2] = temp;
    }
    void siftDown(int pos){
        while (!isLeaf(pos) && elements[pos] < elements[greaterChild(pos)]) {
            int gChild = greaterChild(pos);
            swap(pos, gChild);
            pos = gChild;
        }
    }
    bool isLeaf(int pos) {
        if (pos < 0 || pos >= size)
            throw runtime_error("Index out of range");
        return leftChild(pos) >= size;
    }
    int greaterChild(int pos) {
        if (pos < 0 || pos >= size)
            throw runtime_error("Index out of range");
        if (rightChild(pos) >= size ||
            elements[leftChild(pos)] > elements[rightChild(pos)])
            return leftChild(pos);
        return rightChild(pos);
    }
    void expand(){
        E *temp;
        temp = new E[max*2];
        for(int i = 0; i < size; i++){
            temp[i] = elements[i];
        }
        delete [] elements;
        elements = temp;
        max = max*2;
    }
public:
    MaxHeap(int max = DEFAULT_MAX_SIZE) {
        if (max < 1)
            throw runtime_error("Invalid array size");
        elements = new E[max];
        this->max = max;
        size = 0;
    }
    ~MaxHeap(){
        delete [] elements;
    }
    void insert(E element){
        if (size == max)
            //throw runtime_error("Heap is full");
            expand();
        elements[size] = element;
        siftUp(size);
        size++;
    }
    E first(){
        if (size == 0)
            throw runtime_error("Heap is empty");
        return elements[0];
    }
    E removeFirst(){
        if (size == 0)
            throw runtime_error("Heap is empty");
        return remove(0);
    }
    E remove(int pos){
        if (pos >= size || pos < 0)
            throw runtime_error("Index out of range");
        swap(pos, size - 1);
        size--;
        if(size > 1)
            siftDown(pos);
        return elements[size];
    }
    int getSize() {
        return size;
    }
};

#endif // MAXHEAP_H
