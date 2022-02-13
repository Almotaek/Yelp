#ifndef ArrayListSTRINGS_H
#define ArrayListSTRINGS_H

#include <stdbool.h>

/*
    ArrayLists data structure for char
    designed to hold an array of char pointers

    rptr - array of char*
    size - the size of the array
    numElement - the number of elements in the array
*/
typedef struct ArrayLists {
  char** rptr;
  int size;
  int numElements;
} ArrayLists;

/*
 * create a new ArrayLists
 *
 * @return: a pointer to the newly created ArrayLists
 */
extern ArrayLists* createArrayLists();

/*
 * insert an integer into the ArrayLists at the end of the list
 *
 * @param al - a pointer to the ArrayLists
 * @param s - the item (char*) to be inserted (after the last known element)
 * @return - true if the insertion was succesful, false if not
 *
 */
extern bool insertInArrayLists( ArrayLists*, char* );

/*
 * print the contents of the ArrayLists
 *
 * @param al - pointer to the ArrayLists
 */
extern void printArrayLists( ArrayLists* );

/*
 * get the number of elements in the ArrayLists
 * @param al - a pointer to the ArrayLists
 * @return - the number of elements
 */
extern int getSizes( ArrayLists* );

/*
 * get the space allocated in the ArrayLists
 * @param al - a pointer to the ArrayLists
 * @return - the number of space available for internal implementation
 */
int getSpaces(ArrayLists *al);

/*
 * copies a specified number of elements from source to destination for internal implementation
 *
 * @param src - pointer to the array of char* to be copied FROM
 * @param dest - pointer to the array of char* to be copied TO
 * @param num - number of elements to be copied
 */
void copyDatas(char **src, char **dest, int num);

/*
 * print an element of the ArrayLists at the specified index
 *
 * @param al - pointer to the ArrayLists
 * @param index - index of the element to be printed
 */
void printDataElements(ArrayLists *al, int index);

/*
 * get an element of the ArrayLists at the specified index
 *
 * @param al - pointer to the ArrayLists
 * @param index - index of the element to be returned
 * @return - a pointer to the char stored in the ArrayLists at the specified index
 */
char* getDataElements(ArrayLists *al, int index);

/*
 * check if the ArrayLists has any element
 * @param al - a pointer to the ArrayLists
 * @return - true if ArrayLists has no elemnts, false if not
 */
bool isEmptys(ArrayLists *al);

/*
 * removes a restaurant from the arraylist
 * @param ArrayLists and int, the arraylist to be deleted from and the index
 * @return
 *
 */
void removeFromArrayLists(ArrayLists*,int);


#endif
