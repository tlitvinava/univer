/*#ifndef QUEUE_H
#define QUEUE_H

#include <ctime>
#include <cstdlib>
#include <QRandomGenerator>

class Queue {
public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }
    struct Node {
        int data;
        Node *next;
        Node(int data) : data(data), next(nullptr) {};
    };

    void clear() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
    }

    bool isEmpty() const {
        return size==0;
    }

    int GetSize() const {
        return size;
    }

    //возвращает первый элемент
    int front() const {
        if (isEmpty()) {
            throw "Queue is empty!";
        }
        return head->data;
    }

    //возвращает последний элемент
    int back() const {
        if (isEmpty()) {
            throw "Queue is empty!";
        }
        return tail->data;
    }

    //добавить элемент в конец очереди
    void push(int data) {
        Node *node = new Node(data);
        if (isEmpty()) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        ++size;
    }

    //удалить элемент из начала очереди
    int pop() {
        if (isEmpty()) {
            throw "Queue is empty!";
        }
        int data = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        --size;
        return data;
    }

    void FillQueueRandomly(int x) {
        srand(time(nullptr));
        for (int i = 0; i < x; ++i) {
            //int rand_value = arc4random() % 100;
            int rand_value = QRandomGenerator::global()->bounded(100);

            push(rand_value);
        }
    }

    int peek(int index) const {
        if (isEmpty() || index < 0 || index >= size) {
            throw "Invalid index";
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    void moveMinToFront() {
        if (isEmpty()) {
            throw "Queue is empty";
        }

        // Находим минимальный элемент
        Node *minNode = head;
        Node *current = head;
        Node *prevMinNode = nullptr;
        Node *prev = nullptr;

        while (current->next != nullptr) {
            if (current->next->data < minNode->data) {
                prevMinNode = current;
                minNode = current->next;
            }
            current = current->next;
        }

        // Если минимальный элемент уже первый, ничего делать не нужно
        if (minNode == head) {
            return;
        }

        // Убираем минимальный элемент из его текущей позиции
        if (prevMinNode != nullptr) {
            prevMinNode->next = minNode->next;
        }

        // Перемещаем минимальный элемент в начало
        minNode->next = head;
        head = minNode;

        // Обновляем tail, если минимальный элемент был в конце
        if (minNode == tail) {
            tail = prevMinNode;
        }
    }


private:
    Node *head;  //указатель на начало очереди
    Node *tail;  //указатель на конец очереди
    int size;   //количество элементов в очереди

};

#endif // QUEUE_H
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <ctime>
#include <cstdlib>
#include <QRandomGenerator>

class Queue {
public:
    Queue();
    ~Queue();

    struct Node {
        int value;
        Node *nextNode;
        Node(int value);
    };

    void clearQueue();
    bool isEmpty() const;
    int getSize() const;
    int front() const;
    int back() const;
    void enqueue(int value);
    int dequeue();
    void fillQueueRandomly(int x);
    int peekAt(int index) const;
    void moveMinToFront();

private:
    Node *frontNode;
    Node *backNode;
    int queueSize;

};

#endif // QUEUE_H
