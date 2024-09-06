#ifndef MYTREE_H
#define MYTREE_H

#include "treeNode.h"
#include <QVector>
#include <QPair>

class myTree
{
public:
    myTree();
    ~myTree();
    treeNode* getRoot();
    void insert(QPair<int, QString> pair);
    int search(int key);
    QString searchStringByKey(int key);
    void remove(int key);
    QVector<QPair<int, QString>> getPreOrder();
    QVector<QPair<int, QString>> getPostOrder();
    QVector<QPair<int, QString>> getInOrder();
    void buildTreeFromVector(QVector<QPair<int, QString>> data);
    void balanceTree();

    void countLeavesPerLevel(treeNode* node, QVector<int>& leafCounts, int level);
    QVector<int> getLeavesPerLevel();

private:
    treeNode* root;
    treeNode* insertNode(treeNode* node, QPair<int, QString> pair);
    treeNode* deleteNode(treeNode* node, int key);
    treeNode* findMinimum(treeNode* node);
    treeNode* findNodeByKey(treeNode* node, int key);
    void destroySubTree(treeNode* node);
    void preOrderTraversal(treeNode* node, QVector<QPair<int, QString>>& vec);
    void postOrderTraversal(treeNode* node, QVector<QPair<int, QString>>& vec);
    void inOrderTraversal(treeNode* node, QVector<QPair<int, QString>>& vec);
    treeNode* buildBalancedTreeHelper(QVector<QPair<int, QString>>& sortedPairs, int start, int end);
};

#endif // MYTREE_H
