#include <stdio.h>
#include <stdlib.h>
#include "userInter.h"
#include "loadData.h"
#include "ArrayListStrings.h"


/*
 * tests and starts the program
 * @param
 * @return int indecating the end of the run
 */
int main() {
    BinaryTree *btn;
    BinaryTreel *btl;
    btn = createBinaryTree(); 
    btl = createBinaryTreel(); 
    loadBT(btn,btl);
    startCmd(btn,btl);
    return 0;

}