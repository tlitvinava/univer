#include "myTree.h"

myTree::myTree() : root(nullptr) {}


myTree::~myTree() {
    destroySubTree(root);
}

treeNode *myTree::getRoot()
{
    return root;
}

void myTree::insert(QPair<int, QString> pair) {
    root = insertNode(root, pair);
}

treeNode* myTree::insertNode(treeNode* node, QPair<int, QString> pair) {
    if (node == nullptr) {
        return new treeNode(pair.first, pair.second);
    }

    treeNode* current = node;
    treeNode* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (pair.first < current->key) {
            current = current->left;
        } else if (pair.first > current->key) {
            current = current->right;
        } else {
            return node;
        }
    }

    if (pair.first < parent->key) {
        parent->left = new treeNode(pair.first, pair.second);
    } else {
        parent->right = new treeNode(pair.first, pair.second);
    }

    return node;
}

int myTree::search(int key) {
    treeNode* node = findNodeByKey(root, key);
    if (node != nullptr) {
        return node->key;
    } else {
        return -1;
    }
}

QString myTree::searchStringByKey(int key)
{
    treeNode* node = findNodeByKey(root, key);
    if (node != nullptr) {
        return node->data;
    } else {
        return QString("Key not found");
    }
}

treeNode* myTree::findNodeByKey(treeNode* node, int key) {
    while (node != nullptr && node->key != key) {
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node;
}

void myTree::remove(int key) {
    root = deleteNode(root, key);
}

treeNode* myTree::deleteNode(treeNode* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    treeNode* current = node;
    treeNode* parent = nullptr;

    while (current != nullptr && current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == nullptr) {
        return node;
    }

    // Case 1: Node has no children
    if (current == root) {
        if (current->left == nullptr && current->right == nullptr) {
            delete current;
            return nullptr; // No nodes left in the tree
        } else if (current->left == nullptr) {
            root = current->right;
            delete current;
            return root;
        } else if (current->right == nullptr) {
            root = current->left;
            delete current;
            return root;
        } else {
            treeNode* successor = findMinimum(current->right);
            current->key = successor->key;
            current->data = successor->data;
            current->right = deleteNode(current->right, successor->key);
            return root;
        }
    }
    // Case 2: Node has one child
    else if (current->left == nullptr && current->right == nullptr) {
        if (parent->left == current) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete current;
    }
    // Case 3: Node has one child
    else if (current->left == nullptr) {
        if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        delete current;
    } else if (current->right == nullptr) {
        if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        delete current;
    }
    // Case 4: Node has two children
    else {
        treeNode* successor = findMinimum(current->right);
        current->key = successor->key;
        current->data = successor->data;
        current->right = deleteNode(current->right, successor->key);
    }

    return node;
}

treeNode* myTree::findMinimum(treeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void myTree::destroySubTree(treeNode* node) {
    if (node != nullptr) {
        destroySubTree(node->left);
        destroySubTree(node->right);
        delete node;
    }
}

void myTree::preOrderTraversal(treeNode* node, QVector<QPair<int, QString>>& vec) {
    if (node != nullptr) {
        vec.append(qMakePair(node->key, node->data));
        preOrderTraversal(node->left, vec);
        preOrderTraversal(node->right, vec);
    }
}

QVector<QPair<int, QString>> myTree::getPreOrder() {
    QVector<QPair<int, QString>> result;
    preOrderTraversal(root, result);
    return result;
}

void myTree::postOrderTraversal(treeNode* node, QVector<QPair<int, QString>>& vec) {
    if (node != nullptr) {
        postOrderTraversal(node->left, vec);
        postOrderTraversal(node->right, vec);
        vec.append(qMakePair(node->key, node->data));
    }
}

QVector<QPair<int, QString>> myTree::getPostOrder() {
    QVector<QPair<int, QString>> result;
    postOrderTraversal(root, result);
    return result;
}

void myTree::inOrderTraversal(treeNode* node, QVector<QPair<int, QString>>& vec) {
    if (node != nullptr) {
        inOrderTraversal(node->left, vec);
        vec.append(qMakePair(node->key, node->data));
        inOrderTraversal(node->right, vec);
    }
}

QVector<QPair<int, QString>> myTree::getInOrder() {
    QVector<QPair<int, QString>> result;
    inOrderTraversal(root, result);
    return result;
}

void myTree::buildTreeFromVector(QVector<QPair<int, QString>> data) {
    for (const auto& pair : data) {
        insert(pair);
    }
}

treeNode* myTree::buildBalancedTreeHelper(QVector<QPair<int, QString>>& sortedPairs, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    treeNode* newNode = new treeNode(sortedPairs[mid].first, sortedPairs[mid].second);
    newNode->left = buildBalancedTreeHelper(sortedPairs, start, mid - 1);
    newNode->right = buildBalancedTreeHelper(sortedPairs, mid + 1, end);
    return newNode;
}

void myTree::balanceTree() {
    QVector<QPair<int, QString>> sortedPairs = getInOrder();
    root = buildBalancedTreeHelper(sortedPairs, 0, sortedPairs.size() - 1);
}

void myTree::countLeavesPerLevel(treeNode* node, QVector<int>& leafCounts, int level) {
    if (node == nullptr) {
        return;
    }

    if (level >= leafCounts.size()) {
        leafCounts.resize(level + 1, 0);
    }

    if (node->left == nullptr && node->right == nullptr) {
        leafCounts[level]++;
    }

    countLeavesPerLevel(node->left, leafCounts, level + 1);
    countLeavesPerLevel(node->right, leafCounts, level + 1);
}

QVector<int> myTree::getLeavesPerLevel() {
    QVector<int> leafCounts;
    countLeavesPerLevel(root, leafCounts, 0);
    return leafCounts;
}
