#include "mystack.h"

my_stack::my_stack() {}


bool my_stack::isEmpty() const {
    return top == -1;
}

bool my_stack::isFull() const {
    return top == max_size - 1;
}

int my_stack::size() const {
    return top + 1;
}

void my_stack::clear() {
    top = -1;
}

void my_stack::push(int new_item) {
    if (isFull()) {
        throw "Стек переполнен";
    }
    ++top;
    items[top] = new_item;
}

int my_stack::pop() {
    if (isEmpty()) {
        throw "Стек незаполнен";
    }
    int removed_item = items[top];
    --top;
    return removed_item;
}

int my_stack::peek() const {
    if (!isEmpty()) {
        return items[top];
    }
    throw "Стек незаполнен";
}

QVector<int> my_stack::toQVector() {
    QVector<int> vec;
    for (int i = top; i >= 0; --i) {
        vec.append(items[i]);
    }
    return vec;
}
