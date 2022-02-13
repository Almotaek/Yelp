#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btName.h"
/*
 * Creates a node by allocating space
 * @return: the address of the created node
 */
BTNode* createNode(){
        BTNode* node = (BTNode *)calloc(1, sizeof(BTNode));
        node->parent = NULL;
        node->childL = NULL;
        node->childR = NULL;
        node->name = (char *)malloc(50 * sizeof(char));
        node->al = createArrayList();
}
/*
 * Creates a BST by allocating spcae to it and initilizing some of its values
 * @return: BinaryTree*, the address of the created tree
 */
BinaryTree *createBinaryTree()
{
    BinaryTree *bt = (BinaryTree *)malloc(sizeof(BinaryTree));
    bt->root = NULL;
    bt->size = 0;
    bt->numberofrests = 0;
    return bt;
}
/*
 * insters a restauratn to the BST
 * @param: BinaryTree*, the binary to be insterted in, Restaurant*, the resuarant to be added
 */
void insertInBinaryTree(BinaryTree *bt, Restaurant *r)
{
    // printf("%s\n",r->name);
    // char *x = r->name;
    char* x = (char*)malloc(500*sizeof(char));
    strcpy(x,r->name);

    if (bt->root == NULL)
    {
        // printf("added to root\n");
        bt->root = (BTNode *)calloc(1, sizeof(BTNode));
        bt->root->parent = NULL;
        bt->root->childL = NULL;
        bt->root->childR = NULL;
        bt->root->name = (char *)malloc(strlen(x) * sizeof(char) + 2);
        strcpy(bt->root->name, x);
        bt->root->al = createArrayList();
        insertInArrayList(bt->root->al, r);
        bt->numberofrests = 1;
        bt->size = 1;
    }
    else
    {
        // newnode
        BTNode *aNode = search(bt->root, x);
        if (aNode == (BTNode*) NULL)
        {
            BTNode *newNode = (BTNode *)calloc(1, sizeof(BTNode));
            newNode->name = (char *)malloc(strlen(x) * sizeof(char)+5);
            strcpy(newNode->name, x);
            newNode->al = createArrayList();
            insertInArrayList(newNode->al, r);
            insert(bt->root, newNode);
            bt->numberofrests = bt->numberofrests + 1;
            bt->size = bt->size + 1;
        }
        else
        {
            // printf("Home of %s\n",x);
            insertInArrayList(aNode->al, r);
            bt->numberofrests = bt->numberofrests + 1;

        }
    }
}
/*
 * A recurssive function that insters a node into the the binarytree
 * @param: BTNode*, the node to be inserted onto, and BTNode* then new node
 */
void insert(BTNode *into, BTNode *newNode)
{
    // int a = atoi(into->name);
    // int b = atoi(newNode->name);
    // printf("%s:%d , %s:%d\n",into->name,a,newNode->name,b);
    if (strcmp(into->name, newNode->name) < 0)
    {
        if (into->childR == NULL)
        {
            // printf("added to right\n");
            into->childR = newNode;
            newNode->parent = into;
            // printf("%d is the parent of %d\n",into->value,newNode->value);
        }
        else
        {
            // printf("skipped right\n");
            insert(into->childR, newNode);
        }
    }
    if (strcmp(into->name, newNode->name) > 0)
    {
        if (into->childL == NULL)
        {
            // printf("added to left\n");
            into->childL = newNode;
            newNode->parent = into;
            // printf("%d is the parent of %d\n",into->value,newNode->value);
        }
        else
        {
            // printf("skipped left\n");
            insert(into->childL, newNode);
        }
    }
}
/*
 * function that controls the inorder traversal function
 * @param: BinaryTree*, the tree to be printed, TreeOrder, the enum of the type of traversal
 */
void toStringBinaryTree(BinaryTree *bt, TreeOrder order)
{
    if (bt->root != NULL)
    {
        // char *printbuf = (char *)calloc(bt->size * 50, sizeof(char));
        // call traversals with printbuf
        if (order == INORDER && bt->root != NULL)
        {
            BinaryTreeInOrder(bt->root);
        }

    }
}
/*
 * Prints the BST inorder traversal
 * @param: BTNode, the root of the tree
 */
void BinaryTreeInOrder(BTNode *node)
{
    if (node->childL != NULL)
    {
        BinaryTreeInOrder(node->childL);
    }
    // char numString[400];
    // sprintf(numString, "%s", node->name);
    // strcat(p, numString);

    //printf("%s\n",node->name);
    printArrayList(node->al);


    // printf("Done with Rests in %s\n",node->name);
    if (node->childR != NULL)
    {
        BinaryTreeInOrder(node->childR);
    }
}
/*
 * A recurrisve function that looks for a node in the tree
 * @param: BTNode*, the node to be searched in, char*, the name of the node the is looked for
 * @return: BTNode*, the searched node
 */
BTNode *search(BTNode *into, char *searched)
{
    if (into == NULL)
    {
        // printf("Tree is empty\n");
        return ((BTNode *)NULL);
    }
    if (strcmp(into->name, searched) == 0)
    {
        // printf("%s:%s",into->name, searched);
        // printf("Found :)\n");
        return into;
    }
    if (strcmp(into->name, searched) < 0)
    {
        if (into->childR == NULL)
        {
            // printf("NOT Found :(\n");
            return ((BTNode *)NULL);
        }
        else
        {
            // printf("skipped right\n");
            return search(into->childR, searched);
        }
    }
    if (strcmp(into->name, searched) > 0)
    {
        if (into->childL == NULL)
        {
           // printf("NOT Found :(\n");
            return ((BTNode *)NULL);
        }
        else
        {
            // printf("skipped left\n");
            return search(into->childL, searched);
        }
    }
}
/*
 * Deletes a node from the binary tree
 * @param: BTNode*, the node to be deleted
 * @return: boolean, returns true after each deletion
 */
bool delete(BTNode* node){
    //case1: no children
    if(node->childL==NULL&&node->childR==NULL){

        free(node);
        return true;
    }
    //case2: one child
        //ChildR:
    else if(node->childL==NULL&&node->childR!=NULL){
        //copy the data of childL to node.
        copyNode(node->childR,node);
        //call delete on childL
        delete(node->childR);
        return true;
    }
    else if(node->childR==NULL&&node->childL!=NULL){
        //copy the data of childL to node.
        copyNode(node->childL,node);
        //call delete on childL
        delete(node->childL);
        return true;
    } else{
        //case3 two children
        //node = findMin(of write subtree)
        BTNode* minNode = min(node->childR);
        //copy the data of childL to node.
        copyNode(minNode,node);
        //call delete on childL
        delete(minNode);
        return true;
    }

}
/*
 * Find the minimuim valued node
 * @param:  BTNode*, the node to find the minimum for
 * @return: the minimum node
 */
BTNode* min(BTNode* node){
    if(node->childL==NULL){
        return node;
    }else{
        return min(node->childL);
    }
}
/*
 * Copies the contents of node to another.
 * @param: BTNode* to be copied from, BTNode* to be copied to
 */
void copyNode(BTNode* child, BTNode* node){
    node->name = child->name;
    node->al = child->al;
    node->value = child->value;
}
