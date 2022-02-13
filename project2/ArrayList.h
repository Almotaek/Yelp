#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdbool.h>
#include "Restaurant.h"

/*
    ArrayList data structure for Restaurant
    designed to hold an array of Restaurant pointers

    rptr - array of Restaurant*
    size - the size of the array
    numElement - the number of elements in the array
*/
typedef struct ArrayList {
  Restaurant** rptr;
  int size;
  int numElements;
} ArrayList;

/*
 * create a new ArrayList
 *
 * @return: a pointer to the newly created ArrayList
 */
extern ArrayList* createArrayList();

/*
 * insert an integer into the ArrayList at the end of the list
 *
 * @param al - a pointer to the ArrayList
 * @param s - the item (Restaurant*) to be inserted (after the last known element)
 * @return - true if the insertion was successful, false if not
 *
 */
extern bool insertInArrayList( ArrayList*, Restaurant* );

/*
 * print the contents of the ArrayList
 *
 * @param al - pointer to the ArrayList
 */
extern void printArrayList( ArrayList* );

/*
 * get the number of elements in the ArrayList
 * @param al - a pointer to the ArrayList
 * @return - the number of elements
 */
extern int getSize( ArrayList* );

/*
 * get the space allocated in the ArrayList
 * @param al - a pointer to the ArrayList
 * @return - the number of space available for internal implementation
 */
int getSpace(ArrayList *al);

/*
 * copies a specified number of elements from source to destination for internal implementation
 *
 * @param src - pointer to the array of Restaurant* to be copied FROM
 * @param dest - pointer to the array of Restaurant* to be copied TO
 * @param num - number of elements to be copied
 */
void copyData(Restaurant **src, Restaurant **dest, int num);

/*
 * print an element of the ArrayList at the specified index
 *
 * @param al - pointer to the ArrayList
 * @param index - index of the element to be printed
 */
void printDataElement(ArrayList *al, int index);

/*
 * get an element of the ArrayList at the specified index
 *
 * @param al - pointer to the ArrayList
 * @param index - index of the element to be returned
 * @return - a pointer to the Restaurant stored in the ArrayList at the specified index
 */
Restaurant* getDataElement(ArrayList *al, int index);

/*
 * check if the arraylist has any element
 * @param al - a pointer to the ArrayList
 * @return - true if arraylist has no elemnts, false if not
 */
bool isEmpty(ArrayList *al);

/*
 * removes a restaurant from the arraylist
 * @param ArrayLists and int, the arraylist to be deleted from and the index
 * @return
 *
 */
void removeFromArrayList(ArrayList*,int);


#endif
