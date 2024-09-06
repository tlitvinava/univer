#ifndef TREENODE_H
#define TREENODE_H

#include <QString>

class treeNode
{
public:
    treeNode(int key, QString data);
    treeNode *left;
    treeNode *right;
    int key;
    QString data;
};

#endif // TREENODE_H
