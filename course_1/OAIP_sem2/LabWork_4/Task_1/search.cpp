#include "search.h"
#include "visvector.h"

int Search::BinarySearch(VisVector *vector, int element, int left, int right) {
    if(right == -100) right = vector->Size();

    int middle = (left + right) / 2;
    int currentElement = vector->Read(middle);
    if(currentElement == element) {
        return middle;
    }

    if(left >= right) return -1;

    if(element < currentElement) {
        return BinarySearch(vector, element, left, middle - 1);
    } else {
        return BinarySearch(vector, element, middle + 1, right);
    }
}

int Search::BinarySearch(VisVector *vector, int element) {
    return BinarySearch(vector, element, 0, vector->Size() - 1);
}

