#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ArrayList.h"

/*
 * create a new ArrayList with 0 elements and an array of 10 length
 *
 * @return: a pointer to the newly created ArrayList
 */
ArrayList *createArrayList()
{
  ArrayList *al;
  al = (ArrayList *)malloc(sizeof(ArrayList));
  al->rptr = malloc(10 * sizeof(Restaurant *));
  al->size = 10;
  al->numElements = 0;
  return (al);
}

/*
 * insert an integer into the ArrayList at the end of the list
 *
 * @param al - a pointer to the ArrayList
 * @param s - the item (Restaurant*) to be inserted (after the last known element)
 * @return - true if the insertion was successful, false if not
 *
 * if the array is NOT full, then the new item is inserted after the last known element
 * else the function will allocate a new array (DOUBLE the previous size), 
 * copy the data from the old (existing) array to the new array in the correct locations 
 * and then add the new item after the existing items
 */

bool insertInArrayList(ArrayList *al, Restaurant *r)
{
  if ((al->numElements) == (al->size))
  {
    int newSize = (al->size) * 2;
    Restaurant **dest = (Restaurant **)malloc(newSize * sizeof(Restaurant *));
    copyData(al->rptr, dest, al->numElements);
    al->rptr = dest;
    al->size = newSize;
  }

  al->rptr[(al->numElements)] = r;
  al->numElements = al->numElements + 1;

  return (true);
}

/*
 * get the number of elements in the ArrayList
 * @param al - a pointer to the ArrayList
 * @return - the number of elements
 */
int getSize(ArrayList *al)
{
  return (al->numElements);
}

/*
 * get the space allocated in the ArrayList
 * @param al - a pointer to the ArrayList
 * @return - the number of space available
 */
int getSpace(ArrayList *al)
{
  return (al->size);
}

/*
 * check if the arraylist has any element
 * @param al - a pointer to the ArrayList
 * @return - true if arraylist has no elemnts, false if not
 */
bool isEmpty(ArrayList *al)
{
  return (al->numElements == 0);
}

/*
 * print the contents of the ArrayList
 *
 * @param al - pointer to the ArrayList
 *
 * calls printDataElement to print each element
 */
void printArrayList(ArrayList *al)
{
  if (al->numElements > 0)
  {
    for (int i = 0; i < al->numElements; i++)
    {
      Restaurant* rest = al->rptr[i];
      printRestaurant(rest);
      printf("\n");
    }
    printf("\n");
  }
  // else
  //   printf("Empty array\n");
}

/*
 * print an element of the ArrayList at the specified index
 *
 * @param al - pointer to the ArrayList
 * @param index - index of the element to be printed
 */
void printDataElement(ArrayList *al, int index)
{
  printRestaurant((al->rptr[index]));
}

/*
 * get an element of the ArrayList at the specified index
 *
 * @param al - pointer to the ArrayList
 * @param index - index of the element to be returned
 * @return - a pointer to the Restaurant stored in the ArrayList at the specified index
 */
Restaurant *getDataElement(ArrayList *al, int index)
{
  return al->rptr[index];
}

/*
 * copies a specified number of elements from source to destination
 *
 * @param src - pointer to the array of Restaurant* to be copied FROM
 * @param dest - pointer to the array of Restaurant* to be copied TO
 * @param num - number of elements to be copied
 */
void copyData(Restaurant **src, Restaurant **dest, int num)
{
  for (int i = 0; i < num; i++)
  {
    *dest = *src;
    src++;
    dest++;
  }
}
/*
 * removes a restaurant from the arraylist
 * @param ArrayLists and int, the arraylist to be deleted from and the index
 * @return
 *
 */
void removeFromArrayList(ArrayList* al,int index){
  Restaurant* deleted = al->rptr[index];
  for(int i = index; i<al->numElements-1;i++){
    al->rptr[i]=al->rptr[i+1];
  }
  free(deleted);
  al->numElements = al->numElements-1;

  }
  

