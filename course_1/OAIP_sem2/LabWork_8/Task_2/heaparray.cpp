// #include "heaparray.h"

// template <typename T>
// HeapArray<T>::HeapArray()
// {
//     // implementation
// }

// template <typename T>
// HeapArray<T>::~HeapArray()
// {
//     heap = nullptr;
// }

// template <typename T>
// void HeapArray<T>::siftUp(int index)
// {
//     while (index > 0)
//     {
//         int parent = (index - 1) / 2;
//         if (heap->at(index) <= heap->at(parent))
//         {
//             break;
//         }
//         swap(index, parent);
//         index = parent;
//     }
// }

// template <typename T>
// void HeapArray<T>::siftDown(int index)
// {
//     while (2 * index + 1 < heap->size())
//     {
//         int maxChild = 2 * index + 1;
//         if (maxChild + 1 < heap->size() && heap->at(maxChild + 1) > heap->at(maxChild))
//         {
//             maxChild++;
//         }
//         if (heap->at(index) >= heap->at(maxChild))
//         {
//             break;
//         }
//         swap(index, maxChild);
//         index = maxChild;
//     }}

// template <typename T>
// void HeapArray<T>::swap(int index1, int index2)
// {
//     T temp = heap->at(index1);
//     heap->at(index1) = heap->at(index2);
//     heap->at(index2) = temp;
// }

// template <typename T>
// void HeapArray<T>::insert(T element)
// {
//     heap->push_back(element);
//     siftUp(heap->size() - 1);
//     size++;
// }

// template <typename T>
// T HeapArray<T>::extractMax()
// {
//     if (heap->empty())
//     {
//         throw std::runtime_error("Heap is empty");
//     }
//     T max = heap->at(0);
//     heap->at(0) = heap->at(heap->size() - 1);
//     heap->pop_back();
//     size--;
//     siftDown(0);
//     return max;
// }

// template <typename T>
// T HeapArray<T>::getMax()
// {

//     if (heap->empty())
//     {
//         throw std::runtime_error("Heap is empty");
//     }
//     return heap->at(0);
// }

// template <typename T>
// void HeapArray<T>::remove(int index)
// {

//     if (index < 0 || index >= heap->size())
//     {
//         throw std::runtime_error("Index out of bounds");
//     }
//     heap->at(index) = heap->at(heap->size() - 1);
//     heap->pop_back();
//     siftDown(index);
//     size--;
// }

// template <typename T>
// void HeapArray<T>::changePriority(int index, T element)
// {
//     if (index < 0 || index >= heap->size())
//     {
//         throw std::runtime_error("Index out of bounds");
//     }
//     T old = heap->at(index);
//     heap->at(index) = element;
//     if (element > old)
//     {
//         siftUp(index);
//     }
//     else
//     {
//         siftDown(index);
//     }
// }

// template <typename T>
// void HeapArray<T>::print()
// {
//     for (int i = 0; i < heap->size(); i++)
//     {
//         std::cout << heap->at(i) << " ";
//     }
//     std::cout << std::endl;
// }

// template <typename T>
// bool HeapArray<T>::isEmpty()
// {
//     return heap->empty();
// }

// template <typename T>
// int HeapArray<T>::getSize()
// {
//     return size;
// }

// template <typename T>
// void HeapArray<T>::clear()
// {
//     heap->clear();
//     size = 0;
// }

// template <typename T>
// void HeapArray<T>::drawTree(QGraphicsScene* &scene, int x, int y, int level, int index)
// {
//     if (index >= heap->size())
//     {
//         return;
//     }

//     float tab = 100;
//     if(size > 20)
//     {
//         tab *= (float)size / 20.0;
//     }
//     int offset = tab / (level + 1);

//     scene->addRect(x, y, 20, 20);
//     QGraphicsTextItem* text = scene->addText(QString::number((*heap)[index]));
//     text->setPos(x+2, y-1);

//     int leftIndex = 2*index + 1;
//     if (leftIndex < heap->size())
//     {
//         scene->addLine(x+10, y+20, x-offset+10, y+40);
//         drawTree(scene, x-offset, y+40, level+1, leftIndex);
//     }

//     int rightIndex = 2*index + 2;
//     if (rightIndex < heap->size())
//     {
//         scene->addLine(x+10, y+20, x+offset+10, y+40);
//         drawTree(scene, x+offset, y+40, level+1, rightIndex);
//     }
// }

// template <typename T>
// std::string HeapArray<T>::toString()
// {
//     std::string result = "";
//     for (int i = 0; i < heap->size(); i++)
//     {
//         result += std::to_string(heap->at(i)) + " ";
//     }
//     return result;
// }
