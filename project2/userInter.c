#include "userInter.h"
/*
 * Starts the commands process
 * @param BinaryTree*, BST by name, BinaryTreel* BST by location
 */
void startCmd(BinaryTree *btn, BinaryTreel *btl)
{
    char input;
    char extra;
    while (input != 'x')
    {
        printf("Enter a character (p/s/a/m/w/e/r/x): ");
        input = getchar();
        scanf("%c", &extra);

        if (input == 'p')
        {
            toStringBinaryTree(btn, INORDER);
            // printArrayList(al);
            // printf("Number of Restaurants: %d\n", getSize(al));
        }

        else if (input == 's')
        {
            // printf("you want to search in the the DB\n");
            searchCmd(btl);
        }
        else if(input =='a'){
        addCmd(btn,btl);
    }else if (input=='m'){
        modCmd(btn,btl);
    }else if (input=='w'){
        writeCmd(btl);
    } else if(input=='e'){
        extractCmd(btn,btl);
    }else if(input=='r'){
        removeCmd(btn,btl);
    }

    printf("Program ended.\n");
}
}
/*
 * Starts the search command
 * @param: BinaryTreel* BST by location
 * @return: ArrayList*, list of the found restaurts
 */
ArrayList* searchCmd(BinaryTreel* btl)
{
    char commands[4][500];
    char *commandNames[4] = {"City", "Category", "Cost", "Time"};

    ArrayList* exactMatches=createArrayList();

    for (int i = 0; i < 4; i++)
    {
        printf("%s: ", commandNames[i]);
        fgets(commands[i], 500, stdin);
    }

    bool and = anding(commands[1]);
    //if true then use makeArrayCats and compareANDCats
    //else use makeArrayCatsOR and compareORCats
    ArrayLists* uCats;
    if(and==true){
        uCats = makeArrayOfCats(commands[1]);
    }else{
        uCats = makeArrayOfCatsOR(commands[1]);
    }



     
    if(strcmp(commands[0],"*\n")==0){

    ArrayList* rests = getAllRestsBTL(btl);

    for(int i=0; i<rests->numElements; i++){
        Restaurant* curr = getDataElement(rests,i);
        int cmpCategories =0;
        if(and==true){
            cmpCategories = compareANDCat(curr->cats,uCats);
        }else{
            cmpCategories = compareORCat(curr->cats,uCats);     
        }
        int cmpCity = compareInput(curr->city, commands[0]);
        // int cmpCategories = compareInput(curr->categories, commands[1]);
        int cmpTime = compareInputTime(curr->time, commands[3]);
        if (cmpCity == 0 && cmpCategories == 0 && cmpTime == 0){
             insertInArrayList(exactMatches, curr);
        }
        }
        printf("Restaurants that are EXACT matches: \n\n");
        printArrayList(exactMatches);
        printf("ExactMatches %d\n", getSize(exactMatches));
        printf("\n");

    }else{

    BTNodel* lookingFor = searchl(btl->root,commands[0]);

    if (lookingFor == (BTNodel*) NULL)
    {
        printf("Restaurant not found.\n");
    }else{
        // printf("found in tree");
        ArrayList* arrayRest = lookingFor->al;

        for(int i =0; i<arrayRest->numElements; i++){
            Restaurant *curr = getDataElement(arrayRest, i);
            int cmpCategories =0;
            if(and==true){
                cmpCategories = compareANDCat(curr->cats,uCats);
            }else{
                cmpCategories = compareORCat(curr->cats,uCats);     
            }
            int cmpCity = compareInput(curr->city, commands[0]);
            // int cmpCategories = compareInput(curr->categories, commands[1]);
            int cmpTime = compareInputTime(curr->time, commands[3]);
            // if(strcmp(curr->name,"Panda Express\n") ==0 || strcmp(curr->name,"Panda Express")==0){
            // printf("%s->%s\n",curr->name,commands[0]);
            // printf("%s->%s\n",curr->categories, commands[1]);
            // printf("%d,%d,%d\n",cmpCity,cmpCategories,cmpTime);
            // }
            // printf("%s->%s\n",curr->time, commands[3]);
            if (cmpCity == 0 && cmpCategories == 0 && cmpTime == 0){
                insertInArrayList(exactMatches, curr);
            }
        }
        printf("Restaurants that are EXACT matches: \n\n");
        printArrayList(exactMatches);
        printf("ExactMatches %d\n", getSize(exactMatches));
        printf("\n");
    }
    }
    return exactMatches;
}
/*
 * Starts the add command
 * @param: BinaryTree*, BST by name, BinaryTreel* BST by location
 */
void addCmd(BinaryTree* btn,BinaryTreel* btl){
    char commands[7][500];
    char *commandNames[7] = {"Name","City", "Category", "Time", "Cost", "Rank", "Reviews"};
    for (int i = 0; i < 7; i++)
    {
        printf("%s: ", commandNames[i]);
        fgets(commands[i], 500, stdin);
    }
    char *name; char *city; char *categories; char *time; char *cost; char *rank; char *reviewers;
            name = malloc(200 * sizeof(char));
            strcpy(name, commands[0]);
            city = malloc(200 * sizeof(char));
            strcpy(city, commands[1]);
            categories = malloc(200 * sizeof(char));
            strcpy(categories, commands[2]);
            time = malloc(1000 * sizeof(char));
            strcpy(time, commands[3]);
            cost = malloc(10 * sizeof(char));
            strcpy(cost, commands[4]);
            rank = malloc(10 * sizeof(char));
            strcpy(rank, commands[5]);
            reviewers = malloc(20 * sizeof(char));
            strcpy(reviewers, commands[6]);
    Restaurant* restau = initRestaurant(restau, name, city, categories, time, cost, atof(rank), atoi(reviewers));
    insertInBinaryTree(btn,restau);
    insertInBinaryTreel(btl,restau);

}
/*
 * Starts the modify  command
 * @param: BinaryTree*, BST by name, BinaryTreel* BST by location
 */
void modCmd(BinaryTree* btn,BinaryTreel* btl){
    char commands[7][500];
    char *commandNames[7] = {"Name","City", "New Category", "New Time", "New Cost", "New Rank", "New Reviews"};
    for (int i = 0; i < 7; i++)
    {
        printf("%s: ", commandNames[i]);
        fgets(commands[i], 500, stdin);
    }

    BTNode* lookingFor = search(btn->root,commands[0]);
    ArrayList* arrayRest = lookingFor->al;
    if (lookingFor == (BTNode*) NULL)
    {
        printf("Restaurant not found to mod.\n");
    }else{
        for(int i =0; i<arrayRest->numElements; i++){
            Restaurant *curr = getDataElement(arrayRest, i);
            int cmpCity = compareInput(curr->city, commands[1]);
            if (cmpCity == 0 ){
                curr = modRestaurant(curr,commands[2],commands[3],commands[4],atof(commands[5]),atoi(commands[6]));
                printf("Restaurant was modified!\n");
            }
        }
    }
}
/*
 * Starts the write to txt command
 * @param: BinaryTreel* BST by location
 */
void writeCmd(BinaryTreel* btl){
    char commands[1][500];
    char *commandNames[1] = {"TXT File Name"};
    for (int i = 0; i < 1; i++)
    {
        printf("%s: ", commandNames[i]);
        fgets(commands[i], 500, stdin);
    }
    FILE* fw;
    commands[0][strlen(commands[0])-1]='\0';
    // printf("%sline?",commands[0]);
    fw = fopen(commands[0],"w+");
    ArrayList* rests = getAllRestsBTL(btl);
    for(int i=0; i<rests->numElements; i++){
        Restaurant* r = getDataElement(rests,i);
        putFile(fw,r->name,r->city,r->categories,r->time,r->cost,r->rank,r->reviewers);
        printf("BST successfully writen in the new txt file\n");
    }
    fclose(fw);
}
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
void putFile(FILE* fw, char* name, 
    char* city, 
    char* categories,
    char* time,
    char* cost,
    float rank,
    int reviewers){
        fputs(name,fw);
        fputs(city,fw);
        fputs(categories,fw);
        fputs(time,fw);
        fputs(cost,fw);
        char rankString[100];
        sprintf(rankString,"%.2f\n",rank);
        char reviewersString[100];
        sprintf(reviewersString,"%d\n",reviewers);
        fputs(rankString,fw);
        fputs(reviewersString,fw);
        fputs("\n",fw);
    }
/*
 * Starts the extract command
 * @param: BinaryTree*, BST by name, BinaryTreel* BST by location
 */  
void extractCmd(BinaryTree*btn,BinaryTreel*btl){
    bool byL = false;
    char commands[2][500];
    char *commandNames[2] = {"Name", "City"};
    ArrayList* exactMatches=createArrayList();

    for (int i = 0; i < 2; i++)
    {
        printf("%s: ", commandNames[i]);
        fgets(commands[i], 500, stdin);
    }
    BTNodel* lookingFor = searchl(btl->root,commands[1]);
    BTNode* lookingForN = search(btn->root,commands[0]);

    if(strcmp(commands[0],"*\n")==0){
        byL = true;
    }

    if (lookingFor == (BTNodel*) NULL && byL==true)
    {
        printf("Restaurant not found.\n");
    }else if(lookingFor != (BTNodel*) NULL && byL==true){
        // printf("found in tree");
        ArrayList* arrayRest = lookingFor->al;

        for(int i =0; i<arrayRest->numElements; i++){
            Restaurant *curr = getDataElement(arrayRest, i);
            int cmpName = compareInput(curr->name, commands[0]);
            if (cmpName == 0){
                insertInArrayList(exactMatches, curr);
            }
        }
        printf("Restaurants that are EXACT matches: \n\n");
        printArrayList(exactMatches);
        printf("ExactMatches %d\n", getSize(exactMatches));
        printf("\n");
    }else if(lookingForN == (BTNode*) NULL && byL==false){
        printf("Restaurant not found.\n");
    }else if(lookingForN != (BTNode*) NULL && byL==false){
        // printf("found in tree");
        ArrayList* arrayRest = lookingForN->al;

        for(int i =0; i<arrayRest->numElements; i++){
            Restaurant *curr = getDataElement(arrayRest, i);
            int cmpCity = compareInput(curr->city, commands[1]);
            if (cmpCity == 0 ){
                insertInArrayList(exactMatches, curr);
            }
        }
        printf("Restaurants that are EXACT matches: \n\n");
        printArrayList(exactMatches);
        printf("ExactMatches %d\n", getSize(exactMatches));
        printf("\n");
    }
}
/*
 * Starts the remove command
 * @param: BinaryTree*, BST by name, BinaryTreel* BST by location
 */
void removeCmd(BinaryTree* btn,BinaryTreel* btl){
    bool byL = false;
    char commands[2][500];
    char *commandNames[2] = {"Name", "City"};

    for (int i = 0; i < 2; i++)
    {
        printf("%s: ", commandNames[i]);
        fgets(commands[i], 500, stdin);
    }
    BTNodel* lookingFor = searchl(btl->root,commands[1]);
    BTNode* lookingForN = search(btn->root,commands[0]);

    if(strcmp(commands[0],"*\n")==0){
        byL = true;
    }

    if (lookingFor == (BTNodel*) NULL)
    {
        printf("Restaurant not found to be deleted.\n");
    }else if(lookingFor != (BTNodel*) NULL ){
        // printf("found in tree");
        ArrayList* arrayRest = lookingFor->al;

        for(int i =0; i<arrayRest->numElements; i++){
            Restaurant *curr = getDataElement(arrayRest, i);
            int cmpName = compareInput(curr->name, commands[0]);
            if (cmpName == 0){
                if(arrayRest->numElements <= 1 || strcmp(commands[0],"*\n")==0/*||*CASE*/){
                    printf("deleting from BSTL...\n");                  
                    deletel(lookingFor);
                    }
                else{
                    printf("deleting from array...\n");
                    removeFromArrayList(lookingFor->al,i);
                }
            }
        }
    }
    
    if(lookingForN == (BTNode*) NULL){
        printf("Restaurant not found to be deleted.\n");
    }else if(lookingForN != (BTNode*) NULL ){
        // printf("found in tree");
        ArrayList* arrayRest = lookingForN->al;

        for(int i =0; i<arrayRest->numElements; i++){
            Restaurant *curr = getDataElement(arrayRest, i);
            int cmpCity = compareInput(curr->city, commands[1]);
            if (cmpCity == 0 ){
                if(arrayRest->numElements <= 1 || strcmp(commands[1],"*\n")==0/*||*CASE*/){
                    printf("deleting from BSTN...\n");  
                    delete(lookingForN);
                }else{
                    //delete rest in array
                    printf("deleting from array...\n");
                    removeFromArrayList(lookingForN->al,i);
                }            
                }
        }
    }


}
/*
 * Sees if the user is anding or oring
 * @param: char*, the categories inputted
 */
bool anding(char* longcats){
    for(int i=0; i<strlen(longcats);i++){
        if(longcats[i]==','){
            return true;
        }
    }
    return false;
}
/*
 * Compares arrays with oring condition
 * @param: BinaryTree*, BST by name, BinaryTreel* BST by location
 */
int compareORCat(ArrayLists* rCats ,ArrayLists* uCats){
    char* uC = getDataElements(uCats,0);
    if(strcmp(uC,"*")==0){
        return 0;
    }
    for(int i =0; i<uCats->numElements; i++){
        for(int j=0; j<rCats->numElements; j++){
            char* uCat = getDataElements(uCats,i);
            char* rCat = getDataElements(rCats,j);
            if(strcmp(uCat,rCat)==0){
                return 0;
            }
        }
    }
    return -1;
}
/*
 * Compares arrays with anding condition
 * @param: BinaryTree*, BST by name, BinaryTreel* BST by location
 */
int compareANDCat(ArrayLists* rCats,ArrayLists*uCats){
    char* uC = getDataElements(uCats,0);
    if(strcmp(uC,"*")==0){
        return 0;
    }
    int cmp = -1;
    for(int i =0; i<uCats->numElements; i++){
        for(int j=0; j<rCats->numElements; j++){
            char* uCat = getDataElements(uCats,i);
            char* rCat = getDataElements(rCats,j);
            // printf("-%svs%s-\n",uCat,rCat);
            if(strcmp(uCat,rCat)==0){
                // printf("-%svs%s-is in\n",uCat,rCat);
                cmp = 0;
            }
        }
        if(cmp!=0){
            return -1;
        }
        cmp = -1;
    }
    return 0;
}
/*
 * compares two strings to see if they are equal, compares a Restaurant feature with user input in this case
 *
 * @param *restaurantParam: the Restaurant feature to be compared with
 * @param input: the user input that would be compared with Restaurant feature
 * 
 * @return: an int returning 0 if the two strings match or if user input is * (wild card), returns value of comparator otherwise
 */
int compareInput(char *restaurantParam, char *input)
{

    int cmp;
    int cmps;
    char withSpace[500];

    strcpy(withSpace,input);
    withSpace[strlen(input)-1] = ' ';
    withSpace[strlen(input)] = '\n';
    withSpace[strlen(input)+1] = '\0';



    if (strcmp(input, "*\n") == 0)
    {
        cmp = 0;
    }
    else
    {
        cmp = strcmp(restaurantParam, input);
        cmps = strcmp(withSpace, restaurantParam);
    }
    // printf("orignal: %s, without space: %s\n",restaurantParam,withSpace);
    if(cmps==0){
        return 0;
    }
    return cmp;
}

/*
 * compares Restaurant cost with user input for cost to check if the Restaurant cost is less than or equal to user input 
 *
 * @param *restaurantParam: the Restaurant cost to be compared with
 * @param input: the user input for cost that would be compared with Restaurant cost
 * 
 * @return: an int returning 0 if param1<=param2 or if param2 is * (wild card), returns value of comparator otherwise
 */
int compareInputCost(char *restaurantParam, char *input)
{

    int cmp;

    if (strcmp(input, "*\n") == 0)
    {
        cmp = 0;
    }
    else
    {
        int val = strcmp(restaurantParam, input);
        if (val < 0)
        {
            cmp = 0;
        }
        else
        {
            cmp = val;
        }
    }

    return cmp;
}

/*
 * Splits user input of time into day and time, converts time from hh:mm -> minutes using functions from TimeHandle.c
 * repeats it for each of Restaurants opening hours
 * comapres the two to check if the user input time string matches for day
 * and falls between the opening and closing times of restaurant in minutes
 * 
 * @param *restaurantParam: the Restaurant opening times to be compared with
 * @param input: the user input for time that would be compared with Restaurant opening hours
 * 
 * @return: an int returning 0 if both day and time of user input matches with any opening time for the restaurant parameter
 */
int compareInputTime(char *restaurantParam, char *input)
{

    int cmp = -1;
    if (strcmp(input, "*\n") == 0)
    {

        cmp = 0;
    }
    else
    {

        char *day_time = strdup(input);
        char *day_command = strtok(day_time, " ");
        char *time_command = strtok(NULL, " ");

        int inputTimeToMin = timeToMinutes(time_command);

        int arrCounter = 0;
        int dCmp = -1;
        int tCmp = -1;
        int open_time;
        int close_time;

        char *t = strdup(restaurantParam);
        char *split;
        split = strtok(t, " ");

        while (split != NULL)
        {

            arrCounter++;
            //printf("%s\n", split);

            if (arrCounter == 1)
            {

                dCmp = strcmp(day_command, split);
            }
            else if (arrCounter == 2)
            {

                open_time = timeToMins(split);
            }
            else if (arrCounter == 3)
            {

                close_time = timeToMins(split);

                if (inputTimeToMin >= open_time && inputTimeToMin <= close_time)
                {
                    tCmp = 0;
                }

                if (tCmp == 0 && dCmp == 0)
                {
                    cmp = 0;
                    break;
                }

                arrCounter = 0;
            }

            split = strtok(NULL, ", ");
        }
    }
    return cmp;
}

/*
 * Takes a time string in hh:mm format, 
 * splits it using ":" deliminator into hh and mm parts,
 * converts the total time to minutes using the splitted strings
 *
 * @param *time_command - a pointer to the time string that would be converted
 * @return - time string converted to total minutes
 */
int timeToMinutes(char *time_command)
{
    char *input_time_split = strdup(time_command);
    char *input_time_split1 = strtok(input_time_split, ":");
    char *input_time_split2 = strtok(NULL, ":");

    int inputMin = (atoi(input_time_split1) * 60) + atoi(input_time_split2);

    return inputMin;
}

/*
 * Takes a time string in hh:mm format, 
 * splits it using ":" deliminator into hh and mm parts,
 * converts the total time to minutes using the splitted strings
 *
 * @param *time - a pointer to the time string that would be converted
 * @return - time string converted to total minutes
 * 
 * it is an alternate implementation of the above method, 
 * this specific implementation was more useful in some cases
 */
int timeToMins(char *time)
{
    char *time_split1;
    char *time_split2;
    char *in = strdup(time);
    int length = strlen(in);
    if (length == 4)
    {
        time_split1 = malloc(1 * sizeof(char));
        strncpy(time_split1, in, 1);
        
        time_split2 = malloc(2 * sizeof(char));
        strncpy(time_split2, in + 2, 2);
    }
    else
    {
        time_split1 = malloc(2 * sizeof(char));
        strncpy(time_split1, in, 2);

        time_split2 = malloc(2 * sizeof(char));
        strncpy(time_split2, in + 3, 2);
    }

    int inputMin = (atoi(time_split1) * 60) + atoi(time_split2);

    return inputMin;
}

