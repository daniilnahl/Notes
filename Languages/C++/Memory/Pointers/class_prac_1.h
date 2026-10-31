#ifndef CLASS_PRAC_1_H //first time the file is imported test will pass and all code from here will be imported(Preprocessor will proccess the lines from ifndef down to endif) into mu file.
#define CLASS_PRAC_1_H //if this files is imported a second time in my file then it will be ignored due to ifndef equaling false(switched true to false during first import).

struct class_prac_1{
    //MEMBERS OF CLASS

    //DATA MEMBERS
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};

#endif