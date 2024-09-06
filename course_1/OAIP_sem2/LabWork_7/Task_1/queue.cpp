#include "queue.h"

Queue::Queue() : frontNode(nullptr), backNode(nullptr), queueSize(0) {}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

Queue::Node::Node(int value) : value(value), nextNode(nullptr) {}

void Queue::clearQueue() {
    Node* currentNode = frontNode;
    while (currentNode) {
        Node* tempNode = currentNode;
        currentNode = currentNode->nextNode;
        delete tempNode;
    }
    frontNode = backNode = nullptr;
    queueSize = 0;
}

bool Queue::isEmpty() const {
    return queueSize==0;
}

int Queue::getSize() const {
    return queueSize;
}

int Queue::front() const {
    if (isEmpty()) {
        throw "Очередь пуста!";
    }
    return frontNode->value;
}

int Queue::back() const {
    if (isEmpty()) {
        throw "Очередь пуста!";
    }
    return backNode->value;
}

void Queue::enqueue(int value) {
    Node *node = new Node(value);
    if (isEmpty()) {
        frontNode = backNode = node;
    } else {
        backNode->nextNode = node;
        backNode = node;
    }
    ++queueSize;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw "Очередь пуста!";
    }
    int value = frontNode->value;
    Node *tempNode = frontNode;
    frontNode = frontNode->nextNode;
    delete tempNode;
    --queueSize;
    return value;
}

void Queue::fillQueueRandomly(int x) {
    srand(time(nullptr));
    for (int i = 0; i < x; ++i) {
        int rand_value = QRandomGenerator::global()->bounded(100);
        enqueue(rand_value);
    }
}

int Queue::peekAt(int index) const {
    if (isEmpty() || index < 0 || index >= queueSize) {
        throw "Недопустимый индекс";
    }
    Node* currentNode = frontNode;
    for (int i = 0; i < index; i++) {
        currentNode = currentNode->nextNode;
    }
    return currentNode->value;
}

void Queue::moveMinToFront() {
    if (isEmpty()) {
        throw "Очередь пуста";
    }

    Node *minNode = frontNode;
    Node *currentNode = frontNode;
    Node *prevMinNode = nullptr;
    Node *prevNode = nullptr;

    while (currentNode->nextNode != nullptr) {
        if (currentNode->nextNode->value < minNode->value) {
            prevMinNode = currentNode;
            minNode = currentNode->nextNode;
        }
        currentNode = currentNode->nextNode;
    }

    if (minNode == frontNode) {
        return;
    }

    if (prevMinNode != nullptr) {
        prevMinNode->nextNode = minNode->nextNode;
    }

    minNode->nextNode = frontNode;
    frontNode = minNode;

    if (minNode == backNode) {
        backNode = prevMinNode;
    }
}
