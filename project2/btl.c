#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btl.h"

/*
 * Creates a node by allocating space
 * @return: the address of the created node
 */
BTNodel* createNodel(){
        BTNodel* node = (BTNodel *)calloc(1, sizeof(BTNodel));
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
BinaryTreel *createBinaryTreel()
{
    BinaryTreel *bt = (BinaryTreel *)malloc(sizeof(BinaryTreel));
    bt->root = NULL;
    bt->size = 0;
    bt->numberofrests = 0;
    return bt;
}
/*
 * insters a restauratn to the BST
 * @param: BinaryTree*, the binary to be insterted in, Restaurant*, the resuarant to be added
 */
void insertInBinaryTreel(BinaryTreel *bt, Restaurant *r)
{
    // printf("%s\n",r->name);
    // char *x = r->city;
    char* x = (char*)malloc(500*sizeof(char));
    strcpy(x,r->city);
    if (bt->root == NULL)
    {
        // printf("added to root\n");
        bt->root = (BTNodel *)calloc(1, sizeof(BTNodel));
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
        BTNodel *aNode = searchl(bt->root, x);
        if (aNode == (BTNodel*) NULL)
        {
            BTNodel *newNode = (BTNodel *)calloc(1, sizeof(BTNodel));
            newNode->name = (char *)malloc(strlen(x) * sizeof(char)+5);
            strcpy(newNode->name, x);
            newNode->al = createArrayList();
            insertInArrayList(newNode->al, r);
            insertl(bt->root, newNode);
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
void insertl(BTNodel *into, BTNodel *newNode)
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
            insertl(into->childR, newNode);
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
            insertl(into->childL, newNode);
        }
    }
}
/*
 * function that controls the inorder traversal function
 * @param: BinaryTree*, the tree to be printed, TreeOrder, the enum of the type of traversal
 */
void toStringBinaryTreel(BinaryTreel *bt, TreeOrderl order)
{
    if (bt->root != NULL)
    {
        // call traversals with printbuf
        if (order == INORDERl && bt->root != NULL)
        {
            BinaryTreelInOrder(bt->root);
        }

}
}
/*
 * Prints the BST inorder traversal
 * @param: BTNode, the root of the tree
 */
void BinaryTreelInOrder(BTNodel *node)
{
    if (node->childL != NULL)
    {
        BinaryTreelInOrder(node->childL);
    }
    // char numString[400];
    // sprintf(numString, "%s", node->name);
    // strcat(p, numString);

    // printf("%s\n",node->name);
    printArrayList(node->al);


    // printf("Done with Rests in %s\n",node->name);
    if (node->childR != NULL)
    {
        BinaryTreelInOrder(node->childR);
    }
}
/*
 * Controls the function that gets all the restaurants of the BTS
 * @param: BinaryTree*, the tree that has the restaurants 
 * @return: an arraylist of all the restaurtants in the tree
 */
ArrayList* getAllRestsBTL(BinaryTreel* btl){
    ArrayList* allRests = createArrayList();
    goThroughAllRestsBTL(btl->root,allRests);
    return allRests;
}
/*
 * Gets all the restaurants of the BTS
 * @param: BinaryTree*, the tree that has the restaurants 
 * @return: an arraylist of all the restaurtants in the tree
 */
ArrayList* goThroughAllRestsBTL(BTNodel* node,ArrayList* allRests){
    if (node->childL != NULL)
    {
        goThroughAllRestsBTL(node->childL, allRests);
    }

    ArrayList* arrOfNode = node->al;
    for(int i=0; i<arrOfNode->numElements; i++){
        Restaurant* r = getDataElement(arrOfNode,i);
        // printf("Size of array: %d",arrOfNode->numElements);
        // printRestaurant(r);
        // printf(r->name);
        insertInArrayList(allRests,r);
    }

    if (node->childR != NULL)
    {
        goThroughAllRestsBTL(node->childR, allRests);
    }
}

/*
 * A recurrisve function that looks for a node in the tree
 * @param: BTNode*, the node to be searched in, char*, the name of the node the is looked for
 * @return: BTNode*, the searched node
 */
BTNodel *searchl(BTNodel *into, char *searchled)
{
    if (into == NULL)
    {
        // printf("Tree is empty\n");
        return ((BTNodel *)NULL);
    }
    if (strcmp(into->name, searchled) == 0)
    {
        // printf("%s:%s",into->name, searchled);
        // printf("Found :)\n");
        return into;
    }
    if (strcmp(into->name, searchled) < 0)
    {
        if (into->childR == NULL)
        {
            // printf("NOT Found :(\n");
            return ((BTNodel *)NULL);
        }
        else
        {
            // printf("skipped right\n");
            return searchl(into->childR, searchled);
        }
    }
    if (strcmp(into->name, searchled) > 0)
    {
        if (into->childL == NULL)
        {
           // printf("NOT Found :(\n");
            return ((BTNodel *)NULL);
        }
        else
        {
            // printf("skipped left\n");
            return searchl(into->childL, searchled);
        }
    }
}
/*
 * Deletes a node from the binary tree
 * @param: BTNode*, the node to be deleted
 * @return: boolean, returns true after each deletion
 */
bool deletel(BTNodel* node){
    //case1: no children
    if(node->childL==NULL&&node->childR==NULL){
        free(node);
        return true;
    }
    //case2: one child
        //ChildR:
    if(node->childL==NULL&&node->childR!=NULL){
        //copy the data of childL to node.
        copyNodel(node->childR,node);
        //call delete on childL
        deletel(node->childR);
        return true;
    }
    if(node->childR==NULL&&node->childL!=NULL){
        //copy the data of childL to node.
        copyNodel(node->childL,node);
        //call delete on childL
        deletel(node->childL);
        return true;
    }
    //case3 two children
    //node = findMin(of write subtree)
    BTNodel* minNode = minl(node->childR);
    //copy the data of childL to node.
    copyNodel(minNode,node);
    //call delete on childL
    deletel(minNode);
    return true;
}
/*
 * Find the minimuim valued node
 * @param:  BTNode*, the node to find the minimum for
 * @return: the minimum node
 */
BTNodel* minl(BTNodel* node){
    if(node->childL==NULL){
        return node;
    }else{
        return minl(node->childL);
    }
}
/*
 * Copies the contents of node to another.
 * @param: BTNode* to be copied from, BTNode* to be copied to
 */
void copyNodel(BTNodel* child, BTNodel* node){
    node->name = child->name;
    node->al = child->al;
    node->value = child->value;
}