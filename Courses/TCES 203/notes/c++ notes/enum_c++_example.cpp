#include <iostream>
#include <vector>

enum employee_availability{emp1,emp2,emp3};
int main(){
    if (emp1 == 0){
        std::cout << "Employee 1" << std::endl;
    }


    return 0;
}

enum fruits { apple, orange, banana };

int good_example(){
    int fruit = 1;

    // HARD TO READ
    switch(fruit)
    {
        case 1:
            // code goes here
            break;
        case 2:
            // code goes here
            break;
        case 3:
            // code goes here
            break;
        default:
            // code goes here
            break;
    }


    //EASY TO READ
    switch(fruit)
{
    case fruits::apple:
        // code goes here
        break;
    case fruits::orange:
        // code goes here
        break;
    case fruits::banana:
        // code goes here
        break;
    default:
        // code goes here
        break;
    }
    return 0;
}