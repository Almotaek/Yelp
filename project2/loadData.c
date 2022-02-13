#include "loadData.h"
/*
 * Controls the function that reads from the txt file
 * @param:  BinaryTree*, the BST by name, BinaryTreel*, the BST by location
 */
void loadBT(BinaryTree* btn, BinaryTreel* btl){
    FILE *fPtr;
    fPtr = fopen("restaurants.txt", "r");
    readTxt(btn,btl,fPtr);
}
/*
 * Reads the txt file and populates the BinaryTrees
 * @param: BinaryTree*, BTS Name BinaryTreel* BTS Location ,FILE*, the file object
 */
void readTxt(BinaryTree* btn,BinaryTreel* btl ,FILE* fPtr){
    Restaurant *r;
    char *name; char *city; char *categories; char *time; char *cost; char *rank; char *reviewers;
    int count = 0;
    char ch = getc(fPtr); 
    int cc =0;
    while (!feof(fPtr))
    {
        char *singleLine = calloc(200, sizeof(char));
        fgets(singleLine, 500, fPtr);
        switch (count)
        {
        case 0:
            name = malloc(200 * sizeof(char));
            strcpy(name, singleLine);
            break;
        case 1:
            city = malloc(200 * sizeof(char));
            strcpy(city, singleLine);
            break;
        case 2:
            categories = malloc(200 * sizeof(char));
            strcpy(categories, singleLine);
            break;
        case 3:
            time = malloc(1000 * sizeof(char));
            strcpy(time, singleLine);
            break;
        case 4:
            cost = malloc(10 * sizeof(char));
            strcpy(cost, singleLine);
            break;
        case 5:
            rank = malloc(10 * sizeof(char));
            strcpy(rank, singleLine);
            break;
        case 6:
            reviewers = malloc(20 * sizeof(char));
            strcpy(reviewers, singleLine);
            break;
        }
        count = count + 1;

        if (*singleLine == '\n')
        {
            // r = malloc(sizeof(Restaurant)); //DELETEE??
            r = initRestaurant(r, name, city, categories, time, cost, atof(rank), atoi(reviewers));
            ArrayLists* arrayCats= makeArrayOfCats(categories);
            // printArrayLists(arrayCats);
            initRestCats(r,arrayCats);

            //call makeArrayOfcatigories
            //call a function that adds it to the resaurant, not initRes...
            
            insertInBinaryTree(btn,r);
            insertInBinaryTreel(btl,r);

            count = 0;
        }
    }
    fclose(fPtr);
}
/*
 * Makes an array of ored categories
 * @param: char*, the string that would be splitted
 * @return: the array holding the categories
 */
ArrayLists* makeArrayOfCatsOR(char* longcat){
    ArrayLists* arrayCats = createArrayLists();
    int numCats = 1;
    for(int i=0; i<strlen(longcat); i++){
        if(longcat[i]==' '){
            if(i+1<strlen(longcat)-1){
                if(longcat[i+1]=='O'){
                    if(i+2<strlen(longcat)-1){
                        if(longcat[i+2]=='R'){
                            numCats++;
                        }
                    }

                }

            }
        }
    }
    int places[numCats+1];
    places[0] = 0;
    int k =1;
    for(int i=0; i<strlen(longcat); i++){
        if(longcat[i]==' '){
            if(i+1<strlen(longcat)-1){
                if(longcat[i+1]=='O'){
                    if(i+2<strlen(longcat)-1){
                        if(longcat[i+2]=='R'){
                             places[k] = i+4;
                             k++;
                        }
                    }

                }

            }
        }
    }
    places[numCats] = strlen(longcat)-1;
    for(int i=0; i<numCats; i++){
        // printf("making a string form %d to %d\n",places[i],places[i+1]);
        char* cat;
        if(numCats==1){
            cat = makeString(places[i],places[i+1],longcat); // make sure makesting mallocs cat
        }else{
            if(i==0){
                int num = places[i+1] -4;
                cat = makeString(places[i],num,longcat); // make sure makesting mallocs cat
         }else if(places[i+1]==strlen(longcat)-1){
                int num = places[i+1];
                cat = makeString(places[i],num,longcat); // make sure makesting mallocs cat
             }else{
                int num = places[i+1] -4;
                cat = makeString(places[i],num,longcat); // make sure makesting mallocs cat
         }

        }
        insertInArrayLists(arrayCats,cat);
        // printf("-%s-\n",cat);
    }
    return arrayCats;
}
/*
 * Makes an array of anded categories
 * @param: char*, the string that would be splitted
 * @return: the array holding the categories
 */
ArrayLists* makeArrayOfCats(char* longcat){
    ArrayLists* arrayCats = createArrayLists();
    int numCats = 1;
    for(int i=0; i<strlen(longcat); i++){
        if(longcat[i]==','){
            numCats++;
        }
    }
    int places[numCats+1];
    places[0] = 0;
    int k =1;
    for(int i=0;i<strlen(longcat);i++){
        if(longcat[i]==','){
            places[k] = i+2;
            k++;
        }
    }
    places[numCats] = strlen(longcat)-1;
    // printf("String: %s has new cats on these indexes:\n",longcat);
    for(int i=0; i<numCats; i++){
        // printf("making a string form %d to %d\n",places[i],places[i+1]);
        char* cat;
        if(numCats==1){
            cat = makeString(places[i],places[i+1],longcat); // make sure makesting mallocs cat
        }else{
            if(i==0){
                int num = places[i+1] -2;
                cat = makeString(places[i],num,longcat); // make sure makesting mallocs cat
         }else if(places[i+1]==strlen(longcat)-1){
                int num = places[i+1];
                cat = makeString(places[i],num,longcat); // make sure makesting mallocs cat
             }else{
                int num = places[i+1] -2;
                cat = makeString(places[i],num,longcat); // make sure makesting mallocs cat
         }

        }

         insertInArrayLists(arrayCats,cat);
        //insertin Arraycats
    }
    // printf("The cats of this restau is:\n");
    // printArrayLists(arrayCats);
    // printf("the number of cats in the string: %s is %d\n",longcat,numCats);
    //for loop the call make strings (int,int,string or return it?)

    return arrayCats;

}
/*
 * Makes an array of anded categories
 * @param: char*, the string that would be splitted
 * @return: the array holding the categories
 */
char* makeString(int start,int end,char* longcat){
  char* theCat = (char*)calloc(100,sizeof(char));
  int length = end-start;
  char cat[length];
  for(int i=0; i<length;i++){
      cat[length] = '\0';
  }
  int k =0;
  for(int i = start; i<end; i++){
            cat[k] = longcat[i];
            k++;
  }
  strcpy(theCat,cat);
  return theCat;
}
