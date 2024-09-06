#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <QVector>
#include "mystack.h"

class MyHashTable {
private:
    bool checkPrime(int number);
    int findNextPrime(int number);
    int calculateHash(int key);
public:
    int tableSize;
    QVector<my_stack> hashTable;
    void add(int key, int value);
    void deleteKey(int key);
    MyHashTable(int initialSize);
    void createRandomTable(int itemCount);
    int findMinKeyStack() const;
    QVector<QVector<int>> show();
    void reset();
};

#endif // MYHASHTABLE_H
