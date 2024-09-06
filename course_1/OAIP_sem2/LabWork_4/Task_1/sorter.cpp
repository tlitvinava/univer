#include "sorter.h"
#include "visvector.h"

void Sorter::heapify(VisVector *data, int size, int root) {
    int maxElementIndex = root;
    int maxElementValue = data->Read(maxElementIndex);

    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;

    if (leftChild < size) {
        int leftChildValue = data->Read(leftChild);
        if (leftChildValue > maxElementValue) {
            maxElementIndex = leftChild;
            maxElementValue = leftChildValue;
        }
    }

    if (rightChild < size) {
        int rightChildValue = data->Read(rightChild);
        if (rightChildValue > maxElementValue) {
            maxElementIndex = rightChild;
            maxElementValue = rightChildValue;
        }
    }

    if (maxElementIndex != root) {
        data->Swap(root, maxElementIndex);
        heapify(data, size, maxElementIndex);
    }
}

void Sorter::HeapSort(VisVector *data) {
    for (int i = data->Size() / 2 - 1; i >= 0; i--)
        heapify(data, data->Size(), i);

    for (int i = data->Size() - 1; i > 0; i--) {
        data->Swap(0, i);
        heapify(data, i, 0);
    }
}

// Returns the index of pivot element
int Sorter::Partition(VisVector *data, int start, int end) {
    int pivot = data->Read(end);
    int i = (start - 1); // position of biggest element smaller than pivot

    for (int j = start; j <= end; j++) {
        if (data->Read(j) < pivot) {
            i++;
            data->Swap(i, j);
        }
    }

    data->Swap(i + 1, end);
    return (i + 1);
}

void Sorter::QuickSort(VisVector *data, int start, int end) {
    if (end == -100)
        end = data->Size() - 1;

    if (start < end) {
        int pivotIndex = Partition(data, start, end);

        QuickSort(data, start, pivotIndex - 1);
        QuickSort(data, pivotIndex + 1, end);
    }
}

void Sorter::MergeSort(VisVector *data, int start, int end) {
    if (end == -100)
        end = data->Size() - 1;

    if (start >= end)
        return;
    if (end - start == 1) {
        if (data->Read(start) > data->Read(end))
            data->Swap(start, end);
        return;
    }

    int middle = (end + start) / 2;
    MergeSort(data, start, middle);
    MergeSort(data, middle + 1, end);

    QVector<int> tempArray = {};
    int leftPointer = start;
    int rightPointer = middle + 1;

    while (leftPointer <= middle && rightPointer <= end) {
        int leftValue = data->Read(leftPointer);
        int rightValue = data->Read(rightPointer);
        if (leftValue < rightValue) {
            tempArray.push_back(leftValue);
            leftPointer++;
        } else {
            tempArray.push_back(rightValue);
            rightPointer++;
        }
    }

    while (leftPointer <= middle) {
        tempArray.push_back(data->Read(leftPointer++));
    }

    while (rightPointer <= end) {
        tempArray.push_back(data->Read(rightPointer++));
    }

    for(int i = 0; i < tempArray.count(); i++) {
        data->Write(start + i, tempArray[i]);
    }
}
