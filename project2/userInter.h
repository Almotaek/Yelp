#ifndef USERINTER_H
#define USERINTER_H

#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "btName.h"
#include "btl.h"
#include "loadData.h"

/*
 * Starts the commands process
 * @param BinaryTree*, BST by name, BinaryTreel* BST by location
 */
void startCmd(BinaryTree*,BinaryTreel*);
/*
 * Starts the print process
 */
void printCmd();
/*
 * Starts the search command
 * @param: BinaryTreel* BST by location
 * @return: ArrayList*, list of the found restaurts
 */
ArrayList* searchCmd(BinaryTreel*);
/*
 * Exits the program
 */
void exitCmd();
/*
 * Starts the add command
 * @param: BinaryTree*, BST by name, BinaryTreel* BST by location
 */
void addCmd(BinaryTree*,BinaryTreel*);
/*
 * Starts the modify  command
 * @param: BinaryTree*, BST by name, BinaryTreel* BST by location
 */
void modCmd(BinaryTree*,BinaryTreel*);
/*
 * Starts the write to txt command
 * @param: BinaryTreel* BST by location
 */
void writeCmd(BinaryTreel*);
/*
 * puts strings into a txt file
 * @param: FILE*, the file to be added to
 * @param restaurant- a pointer to the Restaurant to be initialized
 * @param name- name of the Restaurant
 * @param city- city of the Restaurant
 * @param categories- categories of the Restaurant
 * @param time- opening/closing time of the Restaurant
 * @param cost- cost of the Restaurant
 * @param rank- rank of the Restaurant
 * @param reviewers- number of reviewers of the Restaurant
 */
void putFile(FILE*,char* name, 
    char* city, 
    char* categories,
    char* time,
    char* cost,
    float rank,
    int reviewers);
/*
 * Starts the extract command
 * @param: BinaryTree*, BST by name, BinaryTreel* BST by location
 */
void extractCmd(BinaryTree*,BinaryTreel*);
/*
 * Starts the remove command
 * @param: BinaryTree*, BST by name, BinaryTreel* BST by location
 */
void removeCmd(BinaryTree*,BinaryTreel*);
/*
 * Compares arrays with anding condition
 * @param: BinaryTree*, BST by name, BinaryTreel* BST by location
 */
int compareANDCat(ArrayLists*,ArrayLists*);
/*
 * Compares arrays with oring condition
 * @param: BinaryTree*, BST by name, BinaryTreel* BST by location
 */
int compareORCat(ArrayLists*,ArrayLists*);

/*
 * Sees if the user is anding or oring
 * @param: char*, the categories inputted
 */
bool anding(char*);


/*
 * compares two strings to see if they are equal, compares a Restaurant feature with user input in this case
 *
 * @param *restaurantParam: the Restaurant feature to be compared with
 * @param input: the user input that would be compared with Restaurant feature
 * 
 * @return: an int returning 0 if the two strings match or if user input is * (wild card), returns value of comparator otherwise
 */
int compareInput(char* restaurantParam, char* input);

/*
 * comapres user input time with restaurant opening times to check if the user input time falls between the opening and closing times of restaurant
 * 
 * @param *restaurantParam: the Restaurant opening times to be compared with
 * @param input: the user input for time that would be compared with Restaurant opening hours
 * 
 * @return: an int returning 0 if both day and time of user input matches with any opening time for the restaurant parameter
 */
int compareInputTime(char* restaurantParam, char* input);

/*
 * compares Restaurant cost with user input for cost to check if the Restaurant cost is less than or equal to user input 
 *
 * @param *restaurantParam: the Restaurant cost to be compared with
 * @param input: the user input for cost that would be compared with Restaurant cost
 * 
 * @return: an int returning 0 if param1<=param2 or if param2 is * (wild card), returns value of comparator otherwise
 */
int compareInputCost(char* restaurantParam, char* input);

/*
 * Takes a time string in hh:mm format and converts to int total minutes
 *
 * @param *time - a pointer to the time string that would be converted
 * @return - time string converted to total minutes
 */
int timeToMinutes(char *time_command);

/*
 * Takes a time string in hh:mm format and converts to int total minutes
 *
 * @param *time - a pointer to the time string that would be converted
 * @return - time string converted to total minutes
 * 
 * alternate implementation of the above method
 */
int timeToMins(char *time);

#endif
