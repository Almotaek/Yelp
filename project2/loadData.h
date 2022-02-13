#ifndef LOADDATA_H
#define LOADDATA_H
#include "btName.h"
#include "btl.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

/*
 * Controls the function that reads from the txt file
 * @param:  BinaryTree*, the BST by name, BinaryTreel*, the BST by location
 */
void loadBT(BinaryTree*,BinaryTreel*);
/*
 * Reads the txt file and populates the BinaryTrees
 * @param: BinaryTree*, BTS Name BinaryTreel* BTS Location ,FILE*, the file object
 */
void readTxt(BinaryTree*,BinaryTreel*,FILE*);
/*
 * Makes an array of anded categories
 * @param: char*, the string that would be splitted
 * @return: the array holding the categories
 */

ArrayLists* makeArrayOfCats(char*);
/*
 * Makes an array of ored categories
 * @param: char*, the string that would be splitted
 * @return: the array holding the categories
 */
ArrayLists* makeArrayOfCatsOR(char*);
/*
 * Makes an array of anded categories
 * @param: char*, the string that would be splitted
 * @return: the array holding the categories
 */
char* makeString(int,int,char*);

#endif
