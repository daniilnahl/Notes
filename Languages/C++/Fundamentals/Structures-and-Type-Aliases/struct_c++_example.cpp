#include <string>

struct Student // structure name
{
    int studentID;// structure
    std::string name; // members
    short year;
    double gpa;
}; // The ; is required


struct Dimensions
{
int length,
    width,
    height;
//Strcut with a Constructor
    Dimensions(int L, int W, int H)
    {length = L; width = W; height = H;}
};
