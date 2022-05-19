#ifndef MAXHEAP_H
#define MAXHEAP_H

#define DEFAULT_MAX_SIZE 2147483647
#include "KVPair.h"

#include <stdexcept>

using std::runtime_error;

template <typename K,typename V>
class MaxHeap{
private:
    KVPair<K,V> *elements;
    int max;
    int size;

    void siftUp(int pos){
        while (pos > 0 && elements[pos].key> elements[parent(pos)].key){
            swap(pos, parent(pos));
            pos = parent(pos);
        }
    }
    int parent(int pos){
        return (pos - 1) / 2;
    }
    int leftChild(int pos){
        return 2 * pos + 1;
    }
    int rightChild(int pos){
        return 2 * pos + 2;
    }
    void swap(int pos1, int pos2){
        KVPair<K,V> temp = elements[pos1];
        elements[pos1] = elements[pos2];
        elements[pos2] = temp;
    }
    void siftDown(int pos){
        while (!isLeaf(pos) && elements[pos].key< elements[greaterChild(pos)].key){
            int gChild = greaterChild(pos);
            swap(pos, gChild);
            pos = gChild;
        }
    }
    bool isLeaf(int pos){
        if (pos <0 || pos >= size){
            throw runtime_error("Index out of range.");
        }
        return leftChild(pos) >= size;
    }
    int greaterChild(int pos){
        if (pos < 0 || pos >= size){
            throw runtime_error("Index out of range.");
        }
        if (rightChild(pos) >= size ||
            elements[leftChild(pos)].key> elements[leftChild(pos)].key){
            return leftChild(pos);
        }
        return rightChild(pos);

    }

public:
    MaxHeap(int max = DEFAULT_MAX_SIZE){
        this->max = max;
        this->size = 0;
        elements = new KVPair<K,V>[max];
    }
    ~MaxHeap(){
        delete [] elements;
    }
    void insert(K key, V value){
        if (size == max){
            throw runtime_error("Heap is full.");
        }
        elements[size].key = key;
        elements[size].value =value;
        siftUp(size);
        size++;
    }
    V first(){
        if (size == 0){
            throw runtime_error("Heap is empty.");
        }
        return elements[0].value;
    }
    K firstKey(){
        if (size == 0){
            throw runtime_error("Heap is empty.");
        }
        return elements[0].key;
    }
    V remove(){
        if (size == 0){
            throw runtime_error("Heap is empty.");
        }
        V value = elements[0].value;
        elements[0] = elements[size - 1];
        size--;
        siftDown(0);
        return value;
    }
    V getValue(K key){
        for (int i = 0; i < size; i++){
            if (elements[i].key== key){
                return elements[i].getValue();
            }
        }
        throw runtime_error("Key not found.");
    }
    void setValue(K key, V value){
        for (int i = 0; i < size; i++){
            if (elements[i].key== key){
                elements[i].value = value;
                siftUp(i);
                siftDown(i);
                return;
            }
        }
        throw runtime_error("Key not found.");
    }
    bool contains(K key){
        for (int i = 0; i < size; i++){
            if (elements[i].key== key){
                return true;
            }
        }
        return false;
    }
    List<K> *getKeys(){
        List<K> *keys = new List<K>();
        for (int i = 0; i < size; i++){
            keys->insert(elements[i].getKey());
        }
        return keys;
    }
    List<V> *getValues(){
        List<V> *values = new List<V>();
        for (int i = 0; i < size; i++){
            values->insert(elements[i].getValue());
        }
        return values;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size == max;
    }


};

#endif // MAXHEAP_H
