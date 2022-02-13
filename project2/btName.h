#ifndef BINARYTREE
#define BINARYTREE

#define MAXPRINTBUFFER 500

#include "stdbool.h"
#include "ArrayList.h"

/*
 * an enum hodling the ordering type
 */

typedef enum {
    PREORDER,
    INORDER,
    POSTORDER
    } TreeOrder;
/*
 * A struct of a node in the binary search tree holding a name, neghibors andan array list of restauratns
 */
typedef struct BTNode {
    struct BTNode* childR;
    struct BTNode* childL;
    struct BTNode* parent;
    int value; //?
    ArrayList* al;
    char* name;
} BTNode;
/*
 * A struct of the Binary Search Tree holding the root node, the number of nodes, and the number of restaurtants
 */
typedef struct BinaryTree {
    struct BTNode* root;
    int size;
    int numberofrests;
} BinaryTree;
/*
 * Creates a node by allocating space
 * @return: the address of the created node
 */
extern BTNode* createNode();
/*
 * Deletes a node from the binary tree
 * @param: BTNode*, the node to be deleted
 * @return: boolean, returns true after each deletion
 */
extern bool delete(BTNode*);

/*
 * Copies the contents of node to another.
 * @param: BTNode* to be copied from, BTNode* to be copied to
 */
extern void copyNode(BTNode*,BTNode*);
/*
 * Prints the BST inorder traversal
 * @param: BTNode, the root of the tree
 */
extern void BinaryTreeInOrder( BTNode* node );
/*
 * Creates a BST by allocating spcae to it and initilizing some of its values
 * @return: BinaryTree*, the address of the created tree
 */
extern BinaryTree* createBinaryTree();
/*
 * insters a restauratn to the BST
 * @param: BinaryTree*, the binary to be insterted in, Restaurant*, the resuarant to be added
 */
extern void insertInBinaryTree( BinaryTree*, Restaurant* );
/*
 * A recurssive function that insters a node into the the binarytree
 * @param: BTNode*, the node to be inserted onto, and BTNode* then new node
 */
extern void insert(BTNode* into,BTNode* newNode);
/*
 * function that controls the inorder traversal function
 * @param: BinaryTree*, the tree to be printed, TreeOrder, the enum of the type of traversal
 */
extern void toStringBinaryTree( BinaryTree*, TreeOrder );
/*
 * A recurrisve function that looks for a node in the tree
 * @param: BTNode*, the node to be searched in, char*, the name of the node the is looked for
 * @return: BTNode*, the searched node
 */
extern BTNode* search(BTNode*,char*);
/*
 * Gets all the restaurants of the BTS
 * @param: BinaryTree*, the tree that has the restaurants 
 * @return: an arraylist of all the restaurtants in the tree
 */
extern ArrayList* getAllRestsBTN(BinaryTree*);

/*
 * Find the minimuim valued node
 * @param:  BTNode*, the node to find the minimum for
 * @return: the minimum node
 */
extern BTNode* min(BTNode*);



#endif
