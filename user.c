
#include "book_management.h"
#include "user.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct UserArray allUsers ={0,0,0}; // =Database
static struct User *current = NULL;



//prints Database ( =allUsers)
void print_UserArray_Database(){

    printf("\nPRINT_DATABASE: \n");

    int i;
    for(i = 0; i < allUsers.users_number; i++){

        printf("%s|%s|%s\n",allUsers.array[i].username,allUsers.array[i].password,allUsers.array[i].borrowed_book );
    }
    puts("");
}

//creates a struct User
//allocates memory for strings that needs to be freed with free_User()
//borrowed_book has the format "title,authors", can be NULL
struct User create_User(const char* username, const char *password, char *borrowed_book){

    struct User user;

    user.username = strdup(username);
    user.password = strdup(password);

    if(borrowed_book != 0){

        user.borrowed_book= strdup(borrowed_book);
    }else{

        user.borrowed_book =0;
    }


    return user;

}

//eliminates User properly
//frees memory allocated for all strings
void free_User(struct User user){

    free(user.username);
    free(user.password);

    if(user.borrowed_book != 0){

        free(user.borrowed_book);
    }

    return;
}

//stores the Database of Users in the specified file
//returns 0 if users were stored correctly, or an error code otherwise
int store_Users(FILE *file){

    if(file == NULL){
        return -1;
    }

    int err;
    struct User user;

    int i;
    for( i = 0; i< allUsers.users_number; i++){

        user = allUsers.array[i];
        err = fprintf(file, "%s|%s|",user.username, user.password);

        if( err < 0){
            return -2;
        }

        if(user.borrowed_book != 0){

            err = fprintf(file, "%s\n",user.borrowed_book);
        }else{

            err = fprintf(file, "\n");
        }

        if( err < 0){
            return -2;
        }
    }

    return 0;
    
}

//loads the Database of Users from the specified file
//the file must have been generated by a previous call to store_Users()
//returns 0 if users were loaded correctly, or an error code otherwise
int load_Users(FILE *file){

    if(file == NULL){
        return -1;
    }

    char buff[100];
    const char s[2] = "|";
    char *token;

    char *username;
    char *password;
    char *borrowed_book;
    int err;

    while(fgets(buff,100,file) != NULL){ //while there's lines in the file

        //dividing the file line in the respctive struck Book fields, and parsing them to the right types
        token = strtok(buff, s);
        username = strdup(token);

        token = strtok(NULL, s);
        password = strdup(token);

        token = strtok(NULL, "\n");
        if( (token == NULL) ){
            borrowed_book = 0;
        }else{
            borrowed_book = strdup(token);
        }

          
        //create a struct book variable and adding it to the database (AllBooks array)
        err = register_User(create_User(username, password, borrowed_book));
        if( err == -2){
            //printf("%s by %s, already exists in the current database\n", title, authors);
        }


        free(username);
        free(password);
        if(borrowed_book != 0){
            free(borrowed_book);
        }

    }

    return 0;
}

//adds an existing User to the UserArray Database
//returns 0 if the User could be added, or an error code otherwise
//parameter should be user created with create_User()
int register_User(struct User user){


        //making sure we have enough space to add a new user
 		const int users_array_step = 10;
		if(allUsers.users_number + 1 > allUsers.length) { //needs to reallocate

				allUsers.array = realloc(allUsers.array, allUsers.length + users_array_step * sizeof(struct User));
				allUsers.length += users_array_step;
		}



        //making sure this user still doesn't exist in the database
        char* aux_username;

        int i;
        for( i =0; i < allUsers.users_number; i++){

            aux_username = allUsers.array[i].username;
            if ((strcmp(user.username,aux_username ) == 0) ){

                return -2;
            }

        }  

        //if the user doesn't exist in the database, let's add it to the end
		//doing a shallow copy, meaning that the pointers from user and allUsers.array[users_number] point to the same memory blocks
        allUsers.array[allUsers.users_number] = user;
        allUsers.users_number++;//updating number of users in the database


        return 0;

}

//removes User from UserArray Database and eliminates User with free_User()
//returns 0 if the book could be successfully removed, or an error code otherwise.
int remove_User(struct User user){

    //no point in searching if the database is empty
    if(allUsers.users_number == 0){
        return -2;//no users in database
    }

    //searching for the user
    char* aux_username;
    int i =0;
    for( i =0; i < allUsers.users_number; i++){

        aux_username = allUsers.array[i].username;
        if (strcmp(user.username,aux_username ) == 0) {
            //if the user is found, it'll be removed and the users_number will decrement
            break;
        }
    }

    //if we reached the end of the database and couldn't find the user, then it doesn't exist
    if(i == allUsers.users_number){
        return -2;//specified user was not found
    }else{ //else there's a book to be removed, so we'll free its allocated memory
        //i is the position to be removed
        allUsers.users_number--;
        free_User(allUsers.array[i]);
        
    }

    //next step is removing the User and fixing the "hole" left in the array 
    //i is the position to be removed
    for(i; i<allUsers.users_number; i++){

        allUsers.array[i] = allUsers.array[i+1];
    }

    //eliminating the last position, which is being repeated or is the one to be removed, by turning it to null
    struct User aux_user = {};
    allUsers.array[allUsers.users_number] = aux_user;
    

    return 0;
}


//returns 0 if the User could log in, or an error code otherwise
int login_User(char *username, char *password){

        //you need a logout before a new login
        if(current != NULL){

            return -2;
        }

        //if there's a match in the database, login can be done
        char* aux_username;
        char *aux_password;
        int i;
        for( i =0; i < allUsers.users_number; i++){

            aux_username = allUsers.array[i].username;
            aux_password = allUsers.array[i].password;

            if ((strcmp(username,aux_username ) == 0) && strcmp(password, aux_password) ==0){
                current = &allUsers.array[i];
                return 0;//login successful
            }
        }

    //reached the end without finding the username
    return -2;  

}

//not deep deleting any allocated memory, just de-assigning pointers, all users still in UserArray Database
int logout_User(){

    if(current != NULL){

        current = NULL;
        return 0;
    }else{
        return -2;
    }

}

//returns 0 if the User could log in, or an error code otherwise
int find_book_by_title_User(const char *title){

    if(current == NULL){
        return -2;
    }

    struct BookArray books = find_book_by_title(title);

    if(books.array == NULL){

        return -2;
    }

    print_BookArray(books);
    free(books.array);

    return 0;

}

//returns 0 if the User could log in, or an error code otherwise
int find_book_by_authors_User(const char *authors){

    if(current == NULL){
        return -2;
    }
    struct BookArray books = find_book_by_author(authors);

    if(books.array == NULL){

        return -2;
    }

    print_BookArray(books);
    free(books.array);
    
    return 0;

}

//returns 0 if the User could log in, or an error code otherwise
int add_Book_Librarian(struct Book book){

    if(current == NULL){
        return -1;
    }

    int err;

    if ( strcmp(current->username,"librarian")==0 && strcmp(current->password,"librarian")==0 ){
        
        err = add_book(book);
        return err;//if err == -2, book already exists in the library

    }else{
        
        return -3;//not the librarian
    }



}

//returns 0 if the User could log in, or an error code otherwise
int remove_Book_Librarian(struct Book book){

    if(current == NULL){
        return -1;
    }

    int err;

    if ( strcmp(current->username,"librarian")==0 && strcmp(current->password,"librarian")==0 ){


        err = remove_book(book);
        return err;//if err == -2 book doesnt exist in the library

    }else{
        
        return -3;//not the librarian
    }

}

//for the sake of simplicity, each user can only borrow 1 book
// allocates memory for a borrowed_book string
//returns 0 if the User could log in, or an error code otherwise
int borrow_Book_User(const char *title, const char *authors){


    if(current == NULL) {

        return -1;

    }else if(current->borrowed_book != 0){

        return -2; //already borrowed one book
    }

    int err;

    err = borrow_Book(title, authors);
    if(err ==-3){

        return -3;//no copies to borrow for the specified book

    }if(err == -4){

        return -4;//Book not found
    }
    else{

        char *str = malloc(strlen(title) + strlen(authors) + 1 + 1); // +1 for the null-terminator +1 for comma
        strcpy(str, title);
        strcat(str, ",");
        strcat(str, authors);
        current->borrowed_book = str;

    }


    return 0;

}

int return_Book_User(){


    if(current == NULL) {

        return -1;

    }else if(current->borrowed_book == 0){

        return -2; //no book to return
    }

    int err;
    const char s[2] = ",";
    char *token;
    char *title;
    char *authors;    


    token = strtok(current->borrowed_book, s);
    title = strdup(token);

    token = strtok(NULL, s);
    authors =strdup(token);


    err = return_Book(title, authors);

    free(title);
    free(authors);
    
    if(err ==-3){

        return -3;//no registred borrowed copies

    }if(err == -4){

        return -4;//Book not found
    }


    free(current->borrowed_book);
    current->borrowed_book = NULL;


    return 0;


}

//removes everything from UserArray Database properly
void cleanup_UserArray_Database(){ 

    int aux_num = allUsers.users_number;
    int err =0;

    int i;
    for( i =0; i< aux_num;i++){


        err = remove_User(allUsers.array[0]);

        if(err == -2) puts("error cleaning database\n");
    }

    free(allUsers.array);
    allUsers.array =0;
    allUsers.length = 0;

    return ;
}

