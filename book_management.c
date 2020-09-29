#include "book_management.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static struct BookArray allBooks ={0,0,0}; // =Database
//NOTE:  FILE * is the output of fopen() in stdio.h.


//prints Database ( =allBooks)
void print_BookArray_Database(){

    printf("\nPRINT_DATABASE: \n");

    int i;
    for( i = 0; i < allBooks.books_number; i++){

        printf("%s|%s|%d|%d|%d\n",allBooks.array[i].title,allBooks.array[i].authors, allBooks.array[i].year, allBooks.array[i].copies,allBooks.array[i].borrowed );
    }
    puts("");
}

//prints any BookArray
void print_BookArray(struct BookArray books){

    printf("\nPRINT_BOOK_ARRAY: \n");

    int i;
    for( i = 0; i < books.books_number; i++){

        printf("%s|%s|%d|%d|%d\n",books.array[i].title,books.array[i].authors, books.array[i].year, books.array[i].copies,allBooks.array[i].borrowed);
    }
    puts("");

}

//creates a struct Book
//allocates memory for strings that needs to be freed with free_Book()
struct Book create_Book(const char* title,const char* authors, int year, int copies, int borrowed){

    struct Book book1;

    book1.title = strdup(title);
    book1.authors = strdup(authors);
    book1.year = year;    
    book1.copies = copies;
    book1.borrowed = borrowed;

    return book1;

}


//eliminates Book properly
//frees memory allocated for all strings
void free_Book(struct Book book){

    free(book.authors);
    free(book.title);
    return;
}


//stores the Database of Books in the specified file
//returns 0 if books were stored correctly, or an error code otherwise
int store_books(FILE *file){

    if(file == NULL){
        return -1;
    }


    int err;
    struct Book book;

    int i;
    for( i = 0; i< allBooks.books_number; i++){

        book = allBooks.array[i];

        err = fprintf(file, "%s|%s|%d|%d|%d\n",book.title, book.authors,book.year,book.copies, book.borrowed);

        if( err < 0){
            return -2;
        }
    }

    return 0;
    
}


//loads the Database of Books from the specified file
//the file must have been generated by a previous call to store_books()
//returns 0 if books were loaded correctly, or an error code otherwise
int load_books(FILE *file){
//loads from file to BookArray


    if(file == NULL){
        return -1;
    }

    char buff[100];
    const char s[2] = "|";
    char *token;

    char *title;
    char *authors;
    int year, copies, err, borrowed;

    while(fgets(buff,100,file) != NULL){ //while there's lines in the file


        //dividing the file line in the respctive struck Book fields, and parsing them to the right types
        token = strtok(buff, s);
        title = strdup(token);
        //strcpy(title, token);
        token = strtok(NULL, s);
        authors = strdup(token);

        token = strtok(NULL, s);
        year = atoi(token);

        token = strtok(NULL, s);
        copies = atoi(token);

        token = strtok(NULL, s);
        borrowed = atoi(token);

          
        //create a struct book variable and adding it to the database (AllBooks array)
        err = add_book(create_Book(title, authors, year, copies, borrowed));
        if( err == -2){


            //printf("%s by %s, already exists in the current database\n", title, authors);
        }


    }

    return 0;
}


//adding a book to the library means adding the reference to the library, regardless of how many copies exist
//adds an existing Book to the BookArry Database
//returns 0 if the Book could be added, or an error code otherwise
//parameter should to be book created with create_Book()
int add_book(struct Book book){

        //making sure we have enough space to add a new book
 		const int books_array_step = 10;
		if(allBooks.books_number + 1 > allBooks.length) { //needs to reallocate

				allBooks.array = realloc(allBooks.array, allBooks.length + books_array_step * sizeof(struct Book));
				allBooks.length += books_array_step;
		}


        //making sure this book still doesn't exist in the database
        char* aux_title;
        char* aux_authors;

        int i;
        for( i =0; i < allBooks.books_number; i++){

            aux_title = allBooks.array[i].title;
            aux_authors = allBooks.array[i].authors;


            if ((strcmp(book.title,aux_title ) == 0) && (strcmp(book.authors, aux_authors) == 0) ){

                return -2;//Book already exists in the library
            }

        }  

        //if the book doesn't exist in the database, let's add it to the end
		//doing a shallow copy, meaning that the pointers from book and allBooks.array[books_number] point to the same memory blocks
        allBooks.array[allBooks.books_number] = book;
        allBooks.books_number++;//updating number of books in the database



        return 0;

}

//removing book from the library means removing the reference from the library,regardless of how many copies exist and then eliminating it properly
//removes Book from BookArray Database and eliminates Book with free_Book()
//returns 0 if the book could be successfully removed, or an error code otherwise. 
int remove_book(struct Book book){

    //no point in searching if the database is empty
    if(allBooks.books_number == 0){

        //printf("\nNo books in the database\n");
        return -2;
    }

    //searching for the book
    char* aux_title;
    char* aux_authors;
    int aux_year;
    int i;
    for(i =0; i < allBooks.books_number; i++){

        aux_title = allBooks.array[i].title;
        aux_authors = allBooks.array[i].authors;
        aux_year = allBooks.array[i].year;
        if ((strcmp(book.title,aux_title ) == 0) && (strcmp(book.authors, aux_authors) == 0) ){
            

            //if the book is found, it'll be removed and the books_number will decrement
            break;
        }
    }

    //if we reached the end of the database and couldn't find the book, then it doesn't exist
    if(i == allBooks.books_number){
        return -2; 
    }else{
        
        //else there's a book to be removed, so we'll free its allocated memory
        //i is the position to be removed
        allBooks.books_number--;
        free_Book(allBooks.array[i]);
        
    }

    //next step is removing the book and fixing the "hole" left in the array 
    for(i; i<allBooks.books_number; i++){

        allBooks.array[i] = allBooks.array[i+1];
    }

    //eliminating the last position, which is being repeated or is the one to be removed, by turning it to null
    struct Book aux_book = {};
    allBooks.array[allBooks.books_number] = aux_book;
    

    return 0;
}

//finds books with a given title.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
//NOTE: allocates memory! for BookArray.array that needs to be freed with normal free()
struct BookArray find_book_by_title (const char *title){

    struct BookArray books ={0,0,0};

    books.array = realloc( books.array, allBooks.length * sizeof(struct Book) );
	books.length = allBooks.length;
    books.books_number = 0;

    //searching for the book
    char* aux_title;
    int i;
    for( i =0; i < allBooks.books_number; i++){

        aux_title = allBooks.array[i].title;

        if ( (strcmp(title, aux_title ) == 0) ){
            
            //NOTE: not a deep copy, so pointers point to same places as the pointers from allBooks
            books.array[books.books_number] = allBooks.array[i];
            books.books_number++;
            
        }
    }
    if(books.books_number == 0){//no books were found

        free(books.array);
        books.array = NULL;

    }

    return books; 
}

//finds books with the given authors.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
//NOTE: allocates memory! for BookArray.array that needs to be freed with normal free()
struct BookArray find_book_by_author (const char *author){

    struct BookArray books ={0,0,0};

    books.array = realloc( books.array, allBooks.length * sizeof(struct Book) );
	books.length = allBooks.length;
    books.books_number = 0;

    //searching for the book
    char* aux_authors;
    int i;
    for( i =0; i < allBooks.books_number; i++){

        aux_authors = allBooks.array[i].authors;

        if ( (strcmp(author, aux_authors ) == 0) ){
            
            //NOTE: not a deep copy, so pointers point to same places as the pointers from allBooks
            books.array[books.books_number] = allBooks.array[i];
            books.books_number++;
            
        }
    }
    if(books.books_number == 0){//no books were found

        free(books.array);
        books.array = NULL;

    }

    return books; 
}


//finds books published in the given year.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
//NOTE: allocates memory! for BookArray.array that needs to be freed with normal free()
struct BookArray find_book_by_year (unsigned int year){

    struct BookArray books ={0,0,0};

    books.array = realloc( books.array, allBooks.length * sizeof(struct Book) );
	books.length = allBooks.length;
    books.books_number = 0;

    //searching for the book
    unsigned int aux_year;
    int i =0;
    for( i =0; i < allBooks.books_number; i++){

        aux_year = allBooks.array[i].year;

        if ( aux_year == year ){
            
            //NOTE: not a deep copy, so pointers point to same places as the pointers from allBooks
            books.array[books.books_number] = allBooks.array[i];
            books.books_number++;
            
        }
    }
    if(books.books_number == 0){//no books were found

        free(books.array);
        books.array = NULL;

    }

    return books; 
}

//returns 0 if Book could be borrowed, or error code otherwise
int borrow_Book(const char *title, const char *authors){

    //searching for the book
    char* aux_title;
    char* aux_authors;
    int i =0;

    for( i =0; i < allBooks.books_number; i++){

        aux_title = allBooks.array[i].title;
        aux_authors = allBooks.array[i].authors;


        if ( (strcmp(authors, aux_authors ) == 0) && (strcmp(title, aux_title ) == 0) ){
            
            if(allBooks.array[i].copies >0){
                
                allBooks.array[i].copies--;
                allBooks.array[i].borrowed++;
                return 0;

            }else{

                return -3; //no copies to borrow for the specified book
            }

            
        }
    }


    return -4; //reached the end without finding the book 

}

//returns 0 if Book could be returned, or error code otherwise
int return_Book(const char *title, const char *authors){


    //searching for the book
    char* aux_title;
    char* aux_authors;
    int i =0;

    for( i =0; i < allBooks.books_number; i++){

        aux_title = allBooks.array[i].title;
        aux_authors = allBooks.array[i].authors;

        if ( (strcmp(authors, aux_authors ) == 0) && (strcmp(title, aux_title ) == 0) ){
            
            //printf("%s %d\n",allBooks.array[i].title,allBooks.array[i].borrowed );

            if(allBooks.array[i].borrowed >0){
                
                allBooks.array[i].copies++;
                allBooks.array[i].borrowed--;
                return 0;

            }else{

                return -3; //no registred borrowed copies
            }

            
        }
    }

    return -4; //reached the end without finding the book 

}

//removes everything from BookArray Database properly
void cleanup_BookArray_Database(){ 

    int aux_num = allBooks.books_number;
    int err =0;

    int i;
    for( i =0; i< aux_num;i++){


        err = remove_book(allBooks.array[0]);

        if(err == -2) puts("error cleaning database\n");
    }

    free(allBooks.array);
    allBooks.array =0;
    allBooks.length = 0;

    return ;
}
