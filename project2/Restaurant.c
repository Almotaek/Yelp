#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Restaurant.h"

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
Restaurant* initRestaurant( 
    Restaurant* restaurant,
    char* name, 
    char* city, 
    char* categories,
    char* time,
    char* cost,
    float rank,
    int reviewers
){
  restaurant = (Restaurant*) malloc(sizeof(Restaurant));
  restaurant->name =name;
  restaurant->city = city;
  restaurant->categories = categories;
  restaurant->time=time;
  restaurant->cost=cost;
  restaurant->rank=rank;
  restaurant->reviewers=reviewers;
  return restaurant;
}
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
    int reviewers){
      printf("The rest before:\n");
      printRestaurant(restaurant);
      strcpy(restaurant->categories,categories);
      strcpy(restaurant->time,time);
      strcpy(restaurant->cost,cost);
      restaurant->rank=rank;
      restaurant->reviewers = reviewers;
      printf("The rest after:\n");
      printRestaurant(restaurant);
      return restaurant;

    }

/*
 * print the contents of a Restaurant struct
 *
 * @param restaurant - a Restaurant struct whose data is to be printed
 */
void printRestaurant(Restaurant* restaurant){
  printf("%s\n%s\n%s\n%s\n%s\n%.1f\n%d\n", restaurant->name, restaurant->city, restaurant->categories, restaurant->time, restaurant->cost, restaurant->rank, restaurant->reviewers );
  // printf("Name: %s\n", restaurant->cost);
}
/*
 * initlized the category array  of the restaurant
 * @param Restaurant* to be edited, ArrayList*, categories to be added
 */
void initRestCats(Restaurant* r,ArrayLists* al){
  r->cats = al;
}	 
