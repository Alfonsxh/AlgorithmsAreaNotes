//
// Created by alfons on 18-11-22.
//

#ifndef ALGORITHMSTEST_RBTREE_H
#define ALGORITHMSTEST_RBTREE_H

#include <iostream>

using namespace std;

enum RBColor {
    RED,
    BLACK
};

template<typename T>
struct Node {
    RBColor color;
    T key;
    Node *leftChild, *rightChild, *parent;

    Node(T value, RBColor color) : key(value), color(color), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}

    // 返回祖父节点
    Node *grandParent() {
        if (nullptr == this->parent)
            return nullptr;

        return parent->parent;
    }

    void setblack(){
        color = BLACK;
    }

    void setred(){
        color = RED;
    }

    bool isred(){
        return color == RED;
    }
};

template<typename T>
class RBTree {
private:
    Node<T> *m_root;

public:
    RBTree();

    ~RBTree();

    void preOrder();// 前序遍历"红黑树"
    void inOrder(); // 中序遍历"红黑树"
    void postOrder();// 后序遍历"红黑树"

    void insert(T key);// 将结点(key为节点键值)插入到红黑树中
    void insert(Node<T> *node);
    void insertFixUp(Node<T> *node); // 插入修正

    void remove(T key);// 删除结点(key为节点键值)
    void remove(Node<T> *node);
    void removeFixUp(Node<T> *child, Node<T> * parent); // 删除修正

    Node<T>* search(T key); // 根据key查询节点
    Node<T>* search(Node<T> *node, T key); // 从节点node开始，向下寻找值为key的节点

    void print();// 打印红黑树

private:

    void preOrder(Node<T> *tree) const;// 前序遍历"红黑树"
    void inOrder(Node<T> *tree) const;// 中序遍历"红黑树"
    void postOrder(Node<T> *tree) const;// 后序遍历"红黑树"

    void leftRotate(Node<T> *x);  // 左旋
    void rightRotate(Node<T> *x); // 右旋

};

#endif //ALGORITHMSTEST_RBTREE_H
