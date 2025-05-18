1. WHAT ARE CLASSES and OBJECTS?
    Classes are a template for an object. Ex: Car is a class and BMW 2012 i128 is an object made based on that class.

    WHAT ARE THE FOUR TYPES OF METHODS?
        1. Instance = passes the positional {self} argument. Basically normal function.
        2. Static = Functions which don't pass the positional [self] argument. 
        Used to store utilities. Basically like helper functions. 
        Must use a decorator: @staticmethod
        3. Class = Function which take the class itself as a positional argument.
        @classmethod. Basically used for class-wide operations or alternative constructors.
        4. Setter - a method to update or validate an attribute of an object. Basically, function to update object attributes.
        First a @property must be made and then a @<property_name>.setter.

2. HOW TO USE CLASSES and OBJECTS?
    WHAT IS ESSENTIAL FOR CREATING A CLASS?
        __init__ = need to intialize a new instance of a class. Similiar to java when stating this x = x.
        __str__ = prints out the object as a string.
        __dict__ = list all attributes of an object or class.
        dataclasses - auto creates all the boilerplate code. (auto does the self.x = x)
    
    WHAT IS INHERITANCE?
        Technique that allows reusing methods of a class for a subclass. 
        For example vehicle - class, suv - sub class.
        CODE ExAMPLE:
            class Pet:
                def __init__(self, name, weight):
                    self.name = names                   
                    elf.weight = weight

            class Cat(Pet):
                is_feline = True
        
            CLASS Cat inherits all the attribute and methods of Pet class.

        INHERITANCE METHODS?
            super().- allows to directly call a method from parent class.


3. WHEN and WHY TO USE CLASSES and OBJECTS?
    - Use them to organize code in a re-usable manner. 
    - Use it when building scalable, reusable, and modular code.
