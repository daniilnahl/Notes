#include <stdio.h>

void clear_io(){
    while (getchar != "\n");//discards whatever is in input terminal until meets \n
}
int main(){
    int integer, status = 0;
    double db;
    char cmd;
    printf("Menu\n[i] set int\n[d] set double\n[q] quit\n");
    
    while (status != 1){
        printf("Enter command: ");
        scanf("%c",&cmd);
        switch (cmd)
        {
        case 'i':
            printf("Enter integer input: ");
            scanf("%d", &integer);
            clear_io();
            printf("Input is %d", integer);
  
            break;
        case 'd':
            printf("Enter double input: ");
            scanf("%lf", &db);
            printf("Input is %lf", db);
            clear_io();
            break;
        case 'q':
            printf("Quiting program. Bye.\n");
            status = 1;
            clear_io();
            break;
        default:
            printf("Invalid command. Try again.\n");
            break;
        }
    }
    return 0;
}