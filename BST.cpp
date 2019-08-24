#include "BST.h"
#include "student.h"
template class BST<student>;

//===============Global functions===================
// Checks the target nodes left and right pointers and uses rightMost and
// leftMost as needed to find the successor O(log(N))
template <typename Comparable>
node<Comparable> *successor(node<Comparable> *targetNode) {
    if (targetNode->right == nullptr && targetNode->left == nullptr) {
        return nullptr;
    }
    if (targetNode->right != nullptr)
        return leftMost(targetNode->right);

    if (targetNode->right == nullptr && targetNode->left != nullptr)
        return rightMost(targetNode->left);
    return nullptr;
}

// Returns the left most non-null node
// O(log(N))
template <typename Comparable>
node<Comparable> *leftMost(node<Comparable> *startNode) {
    node<Comparable> *current = startNode;

    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Returns the right most non-null node
// O(log(N))
template <typename Comparable>
node<Comparable> *rightMost(node<Comparable> *startNode) {
    node<Comparable> *current = startNode;

    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}
///===============Global functions===================

// BST initializer sets the root node to nullptr
// O(1)
template <typename Comparable> BST<Comparable>::BST() { root = nullptr; }

// BST destructor - frees all of BST's nodes
// O(n)
template <typename Comparable> BST<Comparable>::~BST() { deletePreOrder(root); }

// Returns a student with specific key
// O(log(n))
template <typename Comparable> Comparable BST<Comparable>::getItem(int key) {
    const student targetStudent("foobar", key, -1);
    node<Comparable> *parent = searchNode(root, targetStudent, root);
    student nullStudent("null", -1, -1);
    if (parent == nullptr)
        return nullStudent;
    if (parent->left != nullptr) {
        if (parent->left->data == targetStudent) {
            return parent->left->data;
        }
    }
    if (parent->right != nullptr) {
        if (parent->right->data == targetStudent) {
            return parent->right->data;
        }
    }
    if (parent->data == root->data) {
        return root->data;
    }
    return nullStudent;
}

// Checks to see if root node is null
// O(1)
template <typename Comparable> bool BST<Comparable>::isEmpty() {
    if (root == nullptr)
        return true;
    else
        return false;
}

// Prints the BST in in-order traversial by calling said function
// O(n) where n is how many nodes there are
template <typename Comparable> void BST<Comparable>::printTree() {
    if (!isEmpty()) {
        printInOrder(root);
        std::cout << endl;
    } else {
        std::cout << "Tree is empty!!!";
    }
}

// Inserts a given student into a node in BST
// O(log(n))
template <typename Comparable>
void BST<Comparable>::insert(const Comparable &x) {
    if (root == nullptr) {
        root = createNode(x);
        return;
    } else {
        insertNode(root, createNode(x));
    }
}

// Inserts a given &&student into a node in BST
// O(log(n))
template <typename Comparable> void BST<Comparable>::insert(Comparable &&x) {
    if (root == nullptr) {
        root = createNode(x);
        return;
    } else {
        insertNode(root, createNode(x));
    }
}

// Removes a given student and if it has children
// replaces it w/ next in order child
// O(log(N))
template <typename Comparable>
void BST<Comparable>::remove(const Comparable &x) {

    node<Comparable> *parent = searchNode(root, x, root); // O(log(n))
    bool right;
    node<Comparable> *nodeToRemove;

    if (*const_cast<Comparable *>(&x) == root->data) {
        if (root->left == nullptr && root->right == nullptr) {
            root = nullptr;
            return;
        }
        nodeToRemove = root;
    }
    if (parent != nullptr) {
        if (parent->right != nullptr) {
            if (parent->right->data == x) {
                nodeToRemove = parent->right;
                right = true;
            }
        }
        if (parent->left != nullptr) {
            if (parent->left->data == x) {
                nodeToRemove = parent->left;
                right = false;
            }
        }

        if (nodeToRemove->right == nullptr && nodeToRemove->left == nullptr) {
            (right) ? parent->right = nullptr : parent->left = nullptr;
            return;
        }
        student tmp;
        tmp = successor(nodeToRemove)->data; // O(log(N))

        node<Comparable> *tmpParent = searchNode(root, tmp, root);

        if (tmpParent->right->data == tmp) {
            tmpParent->right = nullptr;
        } else {
            tmpParent->left = nullptr;
        }

        nodeToRemove->data = tmp;
        return;
    }
}

// Removes a student w/ given key
// O(log(N))
template <typename Comparable> void BST<Comparable>::remove(int key) {
    student studentToRemove("foobar", key, -1);
    remove(studentToRemove);
    return;
}

// Updates a nodes data w/ new given data
// O(log(n))
template <typename Comparable>
void BST<Comparable>::update(const Comparable &x) {
    student updatedStudent = *const_cast<Comparable *>(&x);
    node<Comparable> *parent = searchNode(root, x, root);
    if (parent->right->data == updatedStudent) {
        parent->right->data = updatedStudent;
    }
    if (parent->left->data == updatedStudent) {
        parent->left->data = updatedStudent;
    }
}

// Returns a new node w/ data given and no children
// O(1)
template <typename Comparable>
node<Comparable> *BST<Comparable>::createNode(const Comparable &x) {
    node<Comparable> *newStudent = new node<Comparable>;
    newStudent->data = x;
    newStudent->left = newStudent->right = nullptr;
    return newStudent;
}

// Travesrses BST to insert given node
// O(log(n))
template <typename Comparable>
void BST<Comparable>::insertNode(node<Comparable> *current,
                                 node<Comparable> *toInsert) {

    if (toInsert->data < current->data) {
        if (!current->left) {
            current->left = toInsert;
        } else {
            insertNode(current->left, toInsert);
        }
    }
    if (toInsert->data > current->data) {
        if (!current->right) {
            current->right = toInsert;
        } else {
            insertNode(current->right, toInsert);
        }
    }
}

// Travesrses BST in an in-order fashion and prints the students
// O(n) where n is number of studnets in BST
template <typename Comparable>
void BST<Comparable>::printInOrder(node<Comparable> *current) {
    if (current == nullptr) {
        return;
    }
    printInOrder(current->left);
    student currentStudent = current->data;
    currentStudent.printStudent();
    std::cout << "; ";
    printInOrder(current->right);
}

// Returns the parent of the given student in the BST
// O(log(n))
template <typename Comparable>
node<Comparable> *BST<Comparable>::searchNode(node<Comparable> *current,
                                              const Comparable &item,
                                              node<Comparable> *&parent) {

    if (*const_cast<Comparable *>(&item) == current->data) {
        return parent;
    }
    if (*const_cast<Comparable *>(&item) < current->data) {
        if (current->left == nullptr) {
            return nullptr;
        } else {
            return searchNode(current->left, item, current);
        }
    }
    if (*const_cast<Comparable *>(&item) > current->data) {
        if (current->right == nullptr) {
            return nullptr;
        } else {
            return searchNode(current->right, item, current);
        }
    }
    return nullptr;
}

// Frees each of the BST's nodes in a pre-order fashion
// O(n) n is how many nodes there are in BST
template <typename Comparable>
void BST<Comparable>::deletePreOrder(node<Comparable> *current) {
    if (!isEmpty()) {
        if (current == nullptr)
            return;
        node<Comparable> *left = current->left;
        node<Comparable> *right = current->right;
        free(current);
        deletePreOrder(left);
        deletePreOrder(right);
    }
}
