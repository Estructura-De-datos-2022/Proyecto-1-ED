#ifndef TRIENODE_H
#define TRIENODE_H

#include "BSTreeDictionary.h"

class TrieNode{
private:
    Dictionary<char, TrieNode*> *children;



public:
    bool isFinal;
    int prefixCount;
    ArrayList<int>* lineNumbers;
    TrieNode(){
        isFinal = false;
        prefixCount = 0;
        children = new BSTreeDictionary<char, TrieNode*>();
        lineNumbers= new ArrayList<int>();
    }
    ~TrieNode(){
        delete children;
        delete lineNumbers;
    }
    ArrayList<int>* getLineNumbers(){
        return lineNumbers;
    }
    bool contains(char c) {
        return children->contains(c);
    }
    void add(char c){
        TrieNode *newNode = new TrieNode();
        children->insert(c, newNode);
    }
    TrieNode* getChild(char c) {
        return children->getValue(c);
    }
    void remove(char c) {
        children->remove(c);
    }
    List<char>* getChildren(){
        return children->getKeys();
    }
    List<TrieNode*>* getChildrenPointers(){
        return children->getValues();
    }
};

#endif // TRIENODE_H
