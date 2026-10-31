#include <ctype.h>
#include <stdio.h>
#define true 1 //bool flags indentifiers since C does not have a built in bool type
#define false 0

int main(){
    //isspace() function checks if the character is a space, tab, newline, etc.
    char ch = '\n';
    printf("\n%s", isspace(ch) ? "true" : "false");

    //toupper() brings char to upper case

    //tolower() brings char to lower case
    
    return 0;
}