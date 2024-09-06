class VisVector;

class Sorter {
private:
    static void heapify(VisVector *data, int size, int root);
    static int Partition(VisVector *data, int start, int end);

public:
    static void HeapSort(VisVector *vis);
    static void QuickSort(VisVector *data, int start = 0, int end = -100);
    static void MergeSort(VisVector *data, int start = 0, int end = -100);
};
