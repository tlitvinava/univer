#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree() : rootNode(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    clearTree(rootNode);
}

Node* BinarySearchTree::addNode(Node* treeNode, int keyValue, const QString& dataValue) {
    if (treeNode == nullptr) {
        return new Node(keyValue, dataValue);
    }

    if (keyValue < treeNode->key) {
        treeNode->left = addNode(treeNode->left, keyValue, dataValue);
    } else if (keyValue > treeNode->key) {
        treeNode->right = addNode(treeNode->right, keyValue, dataValue);
    } else {
        treeNode->value = dataValue;
    }

    return treeNode;
}

void BinarySearchTree::addNode(int keyValue, const QString& dataValue) {
    rootNode = addNode(rootNode, keyValue, dataValue);
}

Node* BinarySearchTree::deleteNode(Node* treeNode, int keyValue) {
    if (treeNode == nullptr) {
        return nullptr;
    }

    if (keyValue < treeNode->key) {
        treeNode->left = deleteNode(treeNode->left, keyValue);
    } else if (keyValue > treeNode->key) {
        treeNode->right = deleteNode(treeNode->right, keyValue);
    } else {
        if (treeNode->left && treeNode->right) {
            Node* minTreeNode = treeNode->right;
            while (minTreeNode->left != nullptr) {
                minTreeNode = minTreeNode->left;
            }
            treeNode->key = minTreeNode->key;
            treeNode->value = minTreeNode->value;
            treeNode->right = deleteNode(treeNode->right, minTreeNode->key);
        } else if (treeNode->left) {
            treeNode = treeNode->left;
        } else if (treeNode->right) {
            treeNode = treeNode->right;
        } else {
            delete treeNode;
            treeNode = nullptr;
        }
    }

    return treeNode;
}

void BinarySearchTree::deleteNode(int keyValue) {
    rootNode = deleteNode(rootNode, keyValue);
}

Node* BinarySearchTree::findNode(Node* treeNode, int keyValue) {
    if (treeNode == nullptr || treeNode->key == keyValue) {
        return treeNode;
    }

    if (keyValue < treeNode->key) {
        return findNode(treeNode->left, keyValue);
    } else {
        return findNode(treeNode->right, keyValue);
    }
}

QString BinarySearchTree::findNode(int keyValue) {
    Node* treeNode = findNode(rootNode, keyValue);
    return treeNode ? treeNode->value : "";
}

void BinarySearchTree::inOrder(Node* treeNode, QVector<QPair<int, QString>>& result) {
    if (treeNode) {
        inOrder(treeNode->left, result);
        result.push_back(QPair<int, QString>(treeNode->key, treeNode->value));
        inOrder(treeNode->right, result);
    }
}

QVector<QPair<int, QString>> BinarySearchTree::inOrder() {
    QVector<QPair<int, QString>> result;
    inOrder(rootNode, result);
    return result;
}

void BinarySearchTree::preOrder(Node* treeNode, QVector<QPair<int, QString>>& result) {
    if (treeNode) {
        result.push_back(QPair<int, QString>(treeNode->key, treeNode->value));
        preOrder(treeNode->left, result);
        preOrder(treeNode->right, result);
    }
}

QVector<QPair<int, QString>> BinarySearchTree::preOrder() {
    QVector<QPair<int, QString>> result;
    preOrder(rootNode, result);
    return result;
}

void BinarySearchTree::postOrder(Node* treeNode, QVector<QPair<int, QString>>& result) {
    if (treeNode) {
        postOrder(treeNode->left, result);
        postOrder(treeNode->right, result);
        result.push_back(QPair<int, QString>(treeNode->key, treeNode->value));
    }
}

QVector<QPair<int, QString>> BinarySearchTree::postOrder() {
    QVector<QPair<int, QString>> result;
    postOrder(rootNode, result);
    return result;
}

Node* BinarySearchTree::balanceTree(const QVector<QPair<int, QString>>& nodes, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node* treeNode = new Node(nodes[mid].first, nodes[mid].second);
    treeNode->left = balanceTree(nodes, start, mid - 1);
    treeNode->right = balanceTree(nodes, mid + 1, end);
    return treeNode;
}

void BinarySearchTree::balanceTree() {
    QVector<QPair<int, QString>> nodes = inOrder();
    clearTree(rootNode);
    rootNode = balanceTree(nodes, 0, nodes.size() - 1);
}

void BinarySearchTree::clearTree(Node* treeNode) {
    if (treeNode) {
        clearTree(treeNode->left);
        clearTree(treeNode->right);
        delete treeNode;
    }
}

Node* BinarySearchTree::getRoot(){
    return rootNode;
}

void BinarySearchTree::valueOrder(Node* treeNode, QVector<QPair<int, QString>>& result) {
    if (treeNode) {
        valueOrder(treeNode->left, result);
        result.push_back(QPair<int, QString>(treeNode->key, treeNode->value));
        valueOrder(treeNode->right, result);
    }
}

QVector<QPair<int, QString>> BinarySearchTree::valueOrder() {
    QVector<QPair<int, QString>> result;
    valueOrder(rootNode, result);
    std::sort(result.begin(), result.end());

    return result;
}
