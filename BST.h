//
//  BST.h
//
//
//  Created by Resch,Cheryl on 5/15/19.
//

#ifndef BST_h
#define BST_h

#include <iostream>

/***** added by Shashank Ranjan *****/
template <typename Comparable> struct node {
    Comparable data;
    node *left;
    node *right;
};
/***********************************/

template <typename Comparable> class BST {
  public:
    BST();
    ~BST();

    Comparable getItem(int key);
    bool isEmpty();
    void printTree(); // in order traversal of tree

    void insert(const Comparable &x);
    void insert(Comparable &&x);
    void remove(const Comparable &x);
    void remove(int key); // remove the item with the provided key
    /***** added by Shashank Ranjan *****/
    void update(const Comparable &x);
    /***********************************/

    /***** added by Shashank Ranjan *****/
  private:
    node<Comparable> *root;
    node<Comparable> *createNode(const Comparable &x);
    void insertNode(node<Comparable> *current, node<Comparable> *toInsert);
    void printInOrder(node<Comparable> *current);
    node<Comparable> *searchNode(node<Comparable> *current,
                                 const Comparable &item,
                                 node<Comparable> *&parent);
    void deletePreOrder(node<Comparable> *current);
  
    /***********************************/
};

#endif /* BST_h */
