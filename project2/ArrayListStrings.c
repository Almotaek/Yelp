#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ArrayListStrings.h"

/*
 * create a new ArrayLists with 0 elements and an array of 10 length
 *
 * @return: a pointer to the newly created ArrayLists
 */
ArrayLists *createArrayLists()
{
  ArrayLists *al;
  al = (ArrayLists *)malloc(sizeof(ArrayLists));
  al->rptr = malloc(10 * sizeof(char *));
  al->size = 10;
  al->numElements = 0;
  return (al);
}

/*
 * insert an integer into the ArrayLists at the end of the list
 *
 * @param al - a pointer to the ArrayLists
 * @param s - the item (char*) to be inserted (after the last known element)
 * @return - true if the insertion was succesful, false if not
 *
 * if the array is NOT full, then the new item is inserted after the last known element
 * else the function will allocate a new array (DOUBLE the previous size), 
 * copy the data from the old (existing) array to the new array in the correct locations 
 * and then add the new item after the existing items
 */

bool insertInArrayLists(ArrayLists *al, char *r)
{
  if ((al->numElements) == (al->size))
  {
    int newSize = (al->size) * 2;
    char **dest = (char **)malloc(newSize * sizeof(char *));
    copyDatas(al->rptr, dest, al->numElements);
    al->rptr = dest;
    al->size = newSize;
  }

  al->rptr[(al->numElements)] = r;
  al->numElements = al->numElements + 1;

  return (true);
}

/*
 * get the number of elements in the ArrayLists
 * @param al - a pointer to the ArrayLists
 * @return - the number of elements
 */
int getSizes(ArrayLists *al)
{
  return (al->numElements);
}

/*
 * get the space allocated in the ArrayLists
 * @param al - a pointer to the ArrayLists
 * @return - the number of space available
 */
int getSpaces(ArrayLists *al)
{
  return (al->size);
}

/*
 * check if the ArrayLists has any element
 * @param al - a pointer to the ArrayLists
 * @return - true if ArrayLists has no elemnts, false if not
 */
bool isEmptys(ArrayLists *al)
{
  return (al->numElements == 0);
}

/*
 * print the contents of the ArrayLists
 *
 * @param al - pointer to the ArrayLists
 *
 * calls printDataElement to print each element
 */
void printArrayLists(ArrayLists *al)
{
  if (al->numElements > 0)
  {
    for (int i = 0; i < al->numElements; i++)
    {
      char* rest = al->rptr[i];
      printf("%s",rest);
      printf("\n");
    }
    printf("\n");
  }
  // else
  //   printf("Empty array\n");
}

/*
 * print an element of the ArrayLists at the specified index
 *
 * @param al - pointer to the ArrayLists
 * @param index - index of the element to be printed
 */
void printDataElements(ArrayLists *al, int index)
{
  printf("%s",(al->rptr[index]));
}

/*
 * get an element of the ArrayLists at the specified index
 *
 * @param al - pointer to the ArrayLists
 * @param index - index of the element to be returned
 * @return - a pointer to the char stored in the ArrayLists at the specified index
 */
char *getDataElements(ArrayLists *al, int index)
{
  return al->rptr[index];
}

/*
 * copies a specified number of elements from source to destination
 *
 * @param src - pointer to the array of char* to be copied FROM
 * @param dest - pointer to the array of char* to be copied TO
 * @param num - number of elements to be copied
 */
void copyDatas(char **src, char **dest, int num)
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
void removeFromArrayLists(ArrayLists* al,int index){
  for(int i = index-1; i<al->numElements-1;i++){
    al->rptr[i]=al->rptr[i+1];
  }
}

