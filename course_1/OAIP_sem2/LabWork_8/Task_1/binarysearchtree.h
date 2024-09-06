#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "node.h"
#include <QVector>

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void addNode(int keyValue, const QString& dataValue);
    void deleteNode(int keyValue);
    QString findNode(int keyValue);
    QVector<QPair<int, QString>> inOrder();
    QVector<QPair<int, QString>> preOrder();
    QVector<QPair<int, QString>> postOrder();
    void balanceTree();

    Node* getRoot();

    QVector<QPair<int, QString>> valueOrder();

private:
    Node* rootNode;

    Node* addNode(Node* treeNode, int keyValue, const QString& dataValue);
    Node* deleteNode(Node* treeNode, int keyValue);
    Node* findNode(Node* treeNode, int keyValue);
    void inOrder(Node* treeNode, QVector<QPair<int, QString>>& result);
    void preOrder(Node* treeNode, QVector<QPair<int, QString>>& result);
    void postOrder(Node* treeNode, QVector<QPair<int, QString>>& result);
    Node* balanceTree(const QVector<QPair<int, QString>>& nodes, int start, int end);
    void clearTree(Node* treeNode);

    void valueOrder(Node* treeNode, QVector<QPair<int, QString>>& result);
};

#endif // BINARYSEARCHTREE_H
