#ifndef HEAPARRAY_H
#define HEAPARRAY_H

#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsEllipseItem>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

template <typename T>
class HeapArray
{
private:
    std::unique_ptr<std::vector<T>> heapData;
    size_t heapSize = 0;

    void moveUp(int currentIndex)
    {
        while (currentIndex > 0)
        {
            int parentIndex = (currentIndex - 1) / 2;
            if (heapData->at(currentIndex) <= heapData->at(parentIndex))
            {
                break;
            }
            exchange(currentIndex, parentIndex);
            currentIndex = parentIndex;
        }
    }
    void moveDown(int currentIndex)
    {
        while (2 * currentIndex + 1 < heapData->size())
        {
            int maxChildIndex = 2 * currentIndex + 1;
            if (maxChildIndex + 1 < heapData->size() && heapData->at(maxChildIndex + 1) > heapData->at(maxChildIndex))
            {
                maxChildIndex++;
            }
            if (heapData->at(currentIndex) >= heapData->at(maxChildIndex))
            {
                break;
            }
            exchange(currentIndex, maxChildIndex);
            currentIndex = maxChildIndex;
        }
    }
    void exchange(int index1, int index2)
    {
        T temp = heapData->at(index1);
        heapData->at(index1) = heapData->at(index2);
        heapData->at(index2) = temp;
    }
public:
    HeapArray() : heapData(std::make_unique< std::vector<T> >() ){}
    ~HeapArray()
    {
        heapData = nullptr;
    }
    void insert(T element)
    {
        heapData->push_back(element);
        moveUp(heapData->size() - 1);
        heapSize++;
    }
    T extractMax()
    {
        if (heapData->empty())
        {
            throw std::runtime_error("Куча пуста");
        }
        T maxElement = heapData->at(0);
        heapData->at(0) = heapData->at(heapData->size() - 1);
        heapData->pop_back();
        heapSize--;
        moveDown(0);
        return maxElement;
    }
    T getMax()
    {
        if (heapData->empty())
        {
            throw std::runtime_error("Куча пуста");
        }
        return heapData->at(0);
    }
    void remove(int index)
    {
        if (index < 0 || index >= heapData->size())
        {
            throw std::runtime_error("Индекс вышел за границы");
        }
        heapData->at(index) = heapData->at(heapData->size() - 1);
        heapData->pop_back();
        moveDown(index);
        heapSize--;
    }
    void changePriority(int index, T element)
    {
        if (index < 0 || index >= heapData->size())
        {
            throw std::runtime_error("Индекс вышел за границы");
        }
        T oldElement = heapData->at(index);
        heapData->at(index) = element;
        if (element > oldElement)
        {
            moveUp(index);
        }
        else
        {
            moveDown(index);
        }
    }
    void print()
    {
        for (int i = 0; i < heapData->size(); i++)
        {
            std::cout << heapData->at(i) << " ";
        }
        std::cout << std::endl;
    }
    bool isEmpty()
    {
        return heapData->empty();
    }
    int getSize()
    {
        return heapSize;
    }
    void clear()
    {
        heapData->clear();
        heapSize = 0;
    };
    void drawTree(QGraphicsScene* &scene, int x, int y, int level, int index)
    {
        if (index >= heapData->size())
        {
            return;
        }

        float tab = 100;
        if(heapSize > 20)
        {
            tab *= (float)heapSize / 20.0;
        }
        int offset = tab / (level + 1);

        scene->addRect(x, y, 20, 20);
        QGraphicsTextItem* text = scene->addText(QString::number((*heapData)[index]));
        text->setPos(x+2, y-1);

        int leftChildIndex = 2*index + 1;
        if (leftChildIndex < heapData->size())
        {
            scene->addLine(x+10, y+20, x-offset+10, y+40);
            drawTree(scene, x-offset, y+40, level+1, leftChildIndex);
        }

        int rightChildIndex = 2*index + 2;
        if (rightChildIndex < heapData->size())
        {
            scene->addLine(x+10, y+20, x+offset+10, y+40);
            drawTree(scene, x+offset, y+40, level+1, rightChildIndex);
        }
    }
    std::string toString()
    {
        std::string result = "";
        for (int i = 0; i < heapData->size(); i++)
        {
            result += std::to_string(heapData->at(i)) + " ";
        }
        return result;
    }

};

#endif // HEAPARRAY_H

