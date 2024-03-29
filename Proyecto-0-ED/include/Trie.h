#ifndef TRIE_H
#define TRIE_H

#include <stdexcept>
#include <iostream>
#include <string>
#include "TrieNode.h"
#include "HeapPriorityQueue.h"

using std::runtime_error;
using std::cout;
using std::endl;
using std::string;

/**
  * class Trie definida con un TrieNode
  * y los metodos necesario para su implementacion
  * autor: @author Andy, Kevin, Ian
  * version: 1.5
  */

class Trie{
private:
    void operator =(const Trie &other) {}
    Trie(const Trie &other) {}

    TrieNode* root;

    /*
     * funciones auxiliar que ayuda a limpiar el trie
     * resive como parametro un TrieNode
     * recorre el trie y elimina los nodos
     */
    void clearAux(TrieNode *current){
        List<TrieNode*>* pointers = current->getChildrenPointers();
        pointers->goToStart();
        while(!pointers->atEnd()){
            clearAux(pointers->getElement());
            pointers->next();
        }
        delete current;
    }

    /*
     * funcion auxiliar que ayuda a buscar un prefijo en el trie 
     *
     */
    void getMatchesAux(TrieNode *current, string prefix, List<string> *words) {
        if (current->isFinal)
            words->append(prefix);
        List<char> *children = current->getChildren();
        for (children->goToStart(); !children->atEnd(); children->next()){
            string newPrefix = prefix;
            char c = children->getElement();
            newPrefix.append(1, c);
            getMatchesAux(current->getChild(c), newPrefix, words);
        }
        delete children;
    }

    /*
     * funcion auxiliar que ayuda a buscar un prefijo en el trie
     *
     */
    void getMatchesAux2(TrieNode *current, string prefix, HeapPriorityQueue<string> *words) {
        if (current->isFinal){
            ArrayList<int>* numero = current->getLineNumbers();
            words->insert(prefix,numero->getSize());
        }
        List<char> *children = current->getChildren();
        for (children->goToStart(); !children->atEnd(); children->next()){
            string newPrefix = prefix;
            char c = children->getElement();
            newPrefix.append(1, c);
            getMatchesAux2(current->getChild(c), newPrefix, words);
        }
        delete children;
    }

    /*
     * funcion auxiliar que ayuda a buscar las palabras que tiene una cantidad de letras
     * que fue solicitado por el usuario
     */
    void getWordsWithThisLengthAux(TrieNode *current, string prefix, List<string> *words, int length){
        if(current->isFinal){
            if(current->letterNumber==length){
                words->append(prefix);
            }
        }
        else{
            if(current->letterNumber!=length){
                List<char> *children = current->getChildren();
                for (children->goToStart(); !children->atEnd(); children->next()){
                    string newPrefix = prefix;
                    char c = children->getElement();
                    newPrefix.append(1, c);
                    getWordsWithThisLengthAux(current->getChild(c), newPrefix, words, length);
                }
                delete children;
            }
        }
    }
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie(){
        clear();
        delete root;
    }
    void insert(string word,int fileLine){
        TrieNode *current = root;
        if(!containsWord(word)){
            for (unsigned int i = 0; i < word.size(); i++){
                current->prefixCount++;
                if (!current->contains(word[i]))
                    current->add(word[i]);
                current = current->getChild(word[i]);
            }
            current->letterNumber=word.size()-1;
            current->prefixCount++;
            current->isFinal = true;
            current->lineNumbers->append(fileLine);
        }
        else{
            for (unsigned int i = 0; i < word.size(); i++){
                current = current->getChild(word[i]);
            }
            current->lineNumbers->append(fileLine);
        }

    }

    bool containsWord(string word){
        TrieNode *current = root;
        for (unsigned int i = 0; i < word.size(); i++){
            if(!current->contains(word[i]))
                return false;
            current = current->getChild(word[i]);
        }
        return current->isFinal;
    }
    bool containsPrefix(string prefix){
        TrieNode *current = root;
        for (unsigned int i = 0; i < prefix.size(); i++){
            if(!current->contains(prefix[i]))
                return false;
            current = current->getChild(prefix[i]);
        }
        return true;
    }
    int prefixCount(string prefix) {
        TrieNode *current = root;
        for (unsigned int i = 0; i < prefix.size(); i++){
            if(!current->contains(prefix[i]))
                return 0;
            current = current->getChild(prefix[i]);
        }
        return current->prefixCount;
    }
    ArrayList<int>* getLineNumbers(string word){
        TrieNode *current = root;
        for (unsigned int i = 0; i < word.size(); i++){
            if(!current->contains(word[i]))
                return current->getLineNumbers();
            current = current->getChild(word[i]);
        }

        return current->getLineNumbers();
    }
    int getLineNumbersLength(string word){
        TrieNode *current = root;
        for (unsigned int i = 0; i < word.size(); i++){
            if(!current->contains(word[i]))
                return current->getLineNumbers()->getSize();
            current = current->getChild(word[i]);
        }

        return current->getLineNumbers()->getSize();
    }

    void remove(string word) {
        if(!containsWord(word))
            throw runtime_error("Word not found");
        TrieNode *current = root;
        for(unsigned int i = 0; i < word.size(); i++){
            current->prefixCount--;
            TrieNode *child = current->getChild(word[i]);
            if (current->prefixCount == 0)
                delete current;
            else if(child->prefixCount == 1)
                current->remove(word[i]);
            current = child;
        }
        current->prefixCount--;
        if (current->prefixCount == 0)
            delete current;
        else
            current->isFinal = false;
    }
    void clear() {
        clearAux(root);
        root = new TrieNode();
    }
    List<string>* getMatches(string prefix) {
        List<string> *words = new ArrayList<string>();
        TrieNode *current = root;
        for (unsigned int i = 0; i < prefix.size(); i++){
            if(!current->contains(prefix[i]))
                return words;
            current = current->getChild(prefix[i]);
        }
        getMatchesAux(current, prefix, words);
        return words;
    }
    HeapPriorityQueue<string>* getMatches2(string prefix) {
        HeapPriorityQueue<string> *words = new HeapPriorityQueue<string>(root->prefixCount);
        TrieNode *current = root;
        for (unsigned int i = 0; i < prefix.size(); i++){
            if(!current->contains(prefix[i]))
                return words;
            current = current->getChild(prefix[i]);
        }
        getMatchesAux2(current, prefix, words);
        return words;
    }
    List<string>* getWordsWithThisLength(int length) {
        length--;
        List<string> *words = new DLinkedList<string>();
        TrieNode *current = root;
        getWordsWithThisLengthAux(current, "", words, length);
        return words;
    }
};

#endif // TRIE_H
