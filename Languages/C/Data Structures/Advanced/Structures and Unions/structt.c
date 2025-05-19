#include <stdio.h>
#include <string.h>

struct Point {
    int x;
    int y; 
};

struct Book {
    char title[100];
    char author[50];
    int publicationYear;
};
void printBook(struct Book *variable){
    printf("Title, Author, Year: (%s, %s, %d)", variable->title, variable->author, variable->publicationYear);  
}

int main(){
    struct Point p1;
    struct Point p2 = {10, 20};

    p1.x = 5;
    p2.x = 12;
    printf("Point 1: (%d, %d)\n", p1.x, p1.y);

    //pointer to a struct
    struct Point *ptr_p1 = &p1;
    ptr_p1->x = 25;
    ptr_p1->y = 30;
    printf("Point 1 via pointer: (%d, %d)\n", ptr_p1->x, ptr_p1->y);

    //Book example
    struct Book book1;
    strcpy(book1.title, "The Lord of the Rings");
    strcpy(book1.author, "J.R.R. Tolkien");
    book1.publicationYear = 1954;

    printf("Title: %s\n", book1.title);
    printf("Author: %s\n", book1.author);
    printf("Publication Year: %d\n", book1.publicationYear);
    struct Book *book_ptr = &book1;
    printBook(book_ptr);
    return 0;
}

/***
 * TIPS:
 * Use meaningful tag names: Give your structures descriptive names to improve code readability.
    Consider padding: Be aware that the compiler might add padding bytes within a structure to ensure proper alignment of members. This can affect the overall size of the structure.
    Use typedef for convenience: You can use typedef to create an alias for a structure type, making it easier to declare variables:
        typedef struct Point Point;
        Point p3; // Equivalent to struct Point p3;
Initialize structures carefully: Initialize structure members explicitly during declaration or assignment to avoid unexpected values.
 */