//
// Created by alfons on 18-11-22.
//

#include "RbTree.h"


template<typename T>
RBTree<T>::RBTree() {

}

template<typename T>
RBTree<T>::~RBTree() {

}

template<typename T>
void RBTree<T>::preOrder() {
    this->preOrder(this->m_root);
}

template<typename T>
void RBTree<T>::inOrder() {
    this->inOrder(this->m_root);
}

template<typename T>
void RBTree<T>::postOrder() {
    this->postOrder(this->m_root);
}

template<typename T>
void RBTree<T>::insert(T key) {
    Node<T> *z = nullptr;

    if ((z = new Node<T>(RED, key, nullptr, nullptr, nullptr)) == nullptr)
        return;

    this->insert(z);
}

template<typename T>
void RBTree<T>::insert(Node<T> *node) {
    Node<T> *y = nullptr;
    Node<T> *x = this->m_root;

    // 找到插入父节点
    while (x != nullptr) {
        y = x;

        if (node->key > y->key)
            x = x->rightChild;
        else
            x = x->leftChild;
    }
    node->parent = y;

    // 插入
    if (y == nullptr)
        this->m_root = node;
    else {
        if (node->key < y->key)
            y->leftChild = node;
        else
            y->rightChild = node;
    }

    node->setred();

    // 修正
    this->insertFixUp(node);
}


template<typename T>
void RBTree<T>::insertFixUp(Node<T> *node) {
    Node<T> *parent, *grandparent;

    while ((parent = node->parent) != nullptr && parent->isred()) {
        grandparent = node->grandParent();  // 这里不可能出现祖父节点为空的情况，因为根结点一定为黑色，所以如果父节点为根节点会跳出循环

        if (parent == grandparent->leftChild) {     // 父节点是祖父节点的左孩子的情况
            Node<T> *uncle = grandparent->rightChild;

            // case1: 父节点和叔父节点都为红色
            if (uncle != nullptr && uncle->isred()) {   // 叔父节点不为空，并且叔父节点为红色
                parent->setblack();     // 将父节点设置为黑色
                uncle->setblack();      // 叔父节点也设置为黑色
                grandparent->setred();  // 祖父节点设置为红色
                node = grandparent;     // 当前节点指向祖父节点
                continue;
            }

            // case2: 叔父节点为黑色，并且当前节点为右孩子
            if (node == parent->rightChild) {
                this->leftRotate(parent);   // 以父节点为中心进行左旋
                Node<T> *tmp = parent;      // 交换当前节点和父节点，为下一步做准备
                parent = node;
                node = tmp;
            }

            // case3: 叔父节点为黑色，并且当前节点为左孩子
            parent->setblack();     // 将父节点设置为黑色
            grandparent->setred();  // 祖父节点设置为红色
            this->rightRotate(grandparent);     // 以祖父节点为中心进行右旋
        } else {    // 父节点是祖父节点的右孩子的情况
            Node<T> *uncle = grandparent->leftChild;

            // case1: 父节点和叔父节点都为红色
            if (uncle != nullptr && uncle->isred()) {   // 叔父节点不为空，并且叔父节点为红色
                parent->setblack();     // 将父节点设置为黑色
                uncle->setblack();      // 叔父节点也设置为黑色
                grandparent->setred();  // 祖父节点设置为红色
                node = grandparent;     // 当前节点指向祖父节点
                continue;
            }

            // case2: 叔父节点为黑色，并且当前节点为左孩子
            if (node == parent->leftChild) {
                this->rightRotate(parent);  // 以父节点为中心进行右旋
                Node<T> *tmp = parent;      // 交换当前节点和父节点，为下一步做准备
                parent = node;
                node = tmp;
            }

            // case3: 叔父节点为黑色，并且当前节点为右孩子
            parent->setblack();     // 将父节点设置为黑色
            grandparent->setred();  // 祖父节点设置为红色
            this->leftRotate(grandparent);      // 以祖父节点为中心进行左旋
        }
    }

    this->m_root->setblack();
}

template<typename T>
void RBTree<T>::remove(T key) {
    Node<T> *node = this->search(key);

    if (node != nullptr)
        this->remove(node);
}

template<typename T>
void RBTree<T>::remove(Node<T> *node) {

    Node<T> *child, *parent;

    if (node->leftChild != nullptr && node->rightChild != nullptr) {

    }

    // case2: node只有一个孩子
    if (node->leftChild != nullptr)
        child = node->leftChild;
    else
        child = node->rightChild;

    parent = node->parent;

    // 如果孩子节点存在，则将孩子节点的父节点设置为node节点的父节点
    if (child)
        child->parent = parent;

    // 如果父节点不是root节点，则根据node节点的位置，child节点对其进行取代
    if (parent) {
        if (parent->leftChild == node)
            parent->leftChild = child;
        else
            parent->rightChild = child;
    } else {
        this->m_root = child;   // 如果父节点是根结点，则将根结点设置为child节点。
    }

    if (!node->isred())
        this->removeFixUp(child, parent);   // 如果待删除节点是黑色，则需要进行修正

    delete node;    // 最后删除节点
}


template<typename T>
void RBTree<T>::removeFixUp(Node<T> *child, Node<T> *parent) {

}

template<typename T>
Node<T> *RBTree<T>::search(T key) {
    return this->search(this->m_root, key);
}

template<typename T>
Node<T> *RBTree<T>::search(Node<T> *node, T key) {
    if (node == nullptr || node->key == key)
        return node;

    if (node->key < key)
        return this->search(node->rightChild, key);
    else
        return this->search(node->leftChild, key);
}

template<typename T>
void RBTree<T>::print() {

}

/*
 * 对红黑树的节点(x)进行左旋转
 *
 * 左旋示意图(对节点x进行左旋)：
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(左旋)-->           / \                #
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
 *
 *
 */
template<class T>
void RBTree<T>::leftRotate(Node<T> *x) {
    Node<T> *y = x->rightChild;

    x->rightChild = y->leftChild;
    if (y->leftChild != nullptr)
        y->leftChild->parent = x;

    y->parent = x->parent;
    if (x->parent == nullptr)
        this->m_root = x->parent;
    else {
        if (x->parent->leftChild == x)
            x->parent->leftChild = y;
        else
            x->parent->rightChild = y;
    }

    x->parent = y;
    y->leftChild = x;
}

/*
* 对红黑树的节点(y)进行右旋转
*
* 右旋示意图(对节点y进行左旋)：
*            py                               py
*           /                                /
*          y                                x
*         /  \      --(右旋)-->            /  \
*        x   ry                           lx   y
*       / \                                   / \
*      lx  rx                                rx  ry
*
*/
template<typename T>
void RBTree<T>::rightRotate(Node<T> *y) {
    Node<T> *x = y->leftChild;

    y->leftChild = x->rightChild;
    if (x->rightChild != nullptr)
        x->rightChild->parent = y;

    x->parent = y->parent;
    if (y->parent == nullptr)
        this->m_root = nullptr;
    else {
        if (y->parent->leftChild == y)
            y->parent->leftChild = x;
        else
            y->parent->rightChild = x;
    }

    y->parent = x;
    x->rightChild = y;
}


template<typename T>
void RBTree<T>::preOrder(Node<T> *tree) const {
    if (nullptr != tree) {
        this->preOrder(tree->leftChild);
        cout << tree->key << endl;
        this->preOrder(tree->rightChild);
    }
}

template<typename T>
void RBTree<T>::inOrder(Node<T> *tree) const {
    if (nullptr != tree) {
        cout << tree->key << endl;
        this->inOrder(tree->leftChild);
        this->inOrder(tree->rightChild);
    }
}

template<typename T>
void RBTree<T>::postOrder(Node<T> *tree) const {
    if (nullptr != tree) {
        this->postOrder(tree->rightChild);
        this->postOrder(tree->leftChild);
        cout << tree->key << endl;
    }
}
