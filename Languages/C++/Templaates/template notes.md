# What is a template?
Template is a blueprint/formula for creating a function or a class. 
- **Example 1:** when I use vector I am telling computer to convert the template into that specific data type.
- **Example 2:** I want to have a function that calculates a sum and instead of making the same function but for two different types: int and double I create a template and it works.

In both examples the **compiler** is doing all the heavy lifting. Compiler uses the template to make as many overloaded functions as needed.

**C++ supports 3 types of templates**
- Type template parameters (where the template parameter represents a type).
- Non-type template parameters (where the template parameter represents a constexpr value).
- Template template parameters (where the template parameter represents a template).


# How to use a template?
1. First intialize a template/class with a <typename 'any letter'>;
2. Second define a function using that templated. Make the function is of that template type as well.

**On non-template and templates**
You can define a non-template of the template function with defined types. Its especially useful if there is a specific implementation you want to use for a specific data type. Example is shown. 

**Findings**
- Calling a template function is nice, but *can lead to errors if not careful* for example if you try to call max() between an int and double it will cause an error. Basically instantiated functions may not always compile due to compiler errors.

**Warning**
- The compiler will instantiate and compile function templates that do not make sense semantically as long as they are syntactically valid. It is your responsibility to make sure you are calling such function templates with arguments that make sense.


# Cool Facts
- Templates can work with types that didn’t even exist when the template was written. This helps make template code both flexible and future proof!
