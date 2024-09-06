#include "myhashtable.h"

MyHashTable::MyHashTable(int initialSize) {
    tableSize = 10;
    hashTable.resize(tableSize);
}

bool MyHashTable::checkPrime(int number) {
    if (number <= 1)
        return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

int MyHashTable::findNextPrime(int number) {
    while (!checkPrime(number))
        number++;
    return number;
}

int MyHashTable::calculateHash(int key) {
    return abs(key % tableSize);
}

void MyHashTable::add(int key, int value) {
    int index = calculateHash(key);
    hashTable[index].push(value);
}

void MyHashTable::deleteKey(int key) {
    int index = calculateHash(key);
    if (!hashTable[index].isEmpty())
        hashTable[index].pop();
}

void MyHashTable::createRandomTable(int itemCount)
{
    srand(time(0));

    for (int i = 0; i < itemCount; ++i) {
        int value = -50 + rand() % (50 - (-50) + 1);
        add(value, value);
    }
}

QVector<QVector<int>> MyHashTable::show() {
    QVector<QVector<int>> output;
    for (int i = 0; i < tableSize; i++) {
        QVector<int> slotData = hashTable[i].toQVector();
        output.append(slotData);
    }
    return output;
}

void MyHashTable::reset() {
    for (auto &stack : hashTable) {
        stack.clear();
    }
}
