#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "ArrayListStrings.h"
/*
    A Restaurant struct that holds information about a Restaurant

    name- name of the Restaurant
    city- city of the Restaurant
    categories- categories of the Restaurant
    time- opening/closing time of the Restaurant (Day/time)
    cost- cost of the Restaurant ($/ $$/ $$$)
    rank- rank of the Restaurant out of 5
    reviewers- number of reviewers of the Restaurant
*/
typedef struct Restaurant
{
    char *name;
    char *city;
    char *categories;
    char *time;
    char *cost;
    float rank;
    int reviewers;
    ArrayLists* cats;
    
} Restaurant;

/*
 * Initializes a given Restaurant pointers with the values provided in the parameters

 * @param restaurant- a pointer to the Restaurant to be initialized
 * @param name- name of the Restaurant
 * @param city- city of the Restaurant
 * @param categories- categories of the Restaurant
 * @param time- opening/closing time of the Restaurant
 * @param cost- cost of the Restaurant
 * @param rank- rank of the Restaurant
 * @param reviewers- number of reviewers of the Restaurant
 * 
 * @return: a pointer to the Restaurant initialized in the method
 */
Restaurant *initRestaurant(
    Restaurant *restaurant,
    char *name,
    char *city,
    char *categories,
    char *time,
    char *cost,
    float rank,
    int reviewers);

/*
 * print the contents of a Restaurant struct
 *
 * @param restaurant - a Restaurant struct whose data is to be printed
 */
void printRestaurant(Restaurant* restaurant);

/*
 * Modifies the restaurtants
 * @param: Restaurant *restaurant, the restaurant to be edited
 * @param restaurant- a pointer to the Restaurant to be initialized
 * @param name- name of the Restaurant
 * @param city- city of the Restaurant
 * @param categories- categories of the Restaurant
 * @param time- opening/closing time of the Restaurant
 * @param cost- cost of the Restaurant
 * @param rank- rank of the Restaurant
 * @param reviewers- number of reviewers of the Restaurant
 * @return: the array holding the categories
 */
Restaurant *modRestaurant(
    Restaurant *restaurant,
    char *categories,
    char *time,
    char *cost,
    float rank,
    int reviewers);

/*
 * initlized the category array  of the restaurant
 * @param Restaurant* to be edited, ArrayList*, categories to be added
 */
void initRestCats(Restaurant*,ArrayLists*);



#endif