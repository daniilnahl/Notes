# 1. What is Inheritance?

Inheritance allows sharing code between classes. For example: `Animal -> Dog -> Labrador`.

### Vocabulary

1. **Is-a Relationship**: A hierarchical connection between two categories in which one type is a specialized version of the other.  
2. **Inheritance Hierarchy**: A set of hierarchical relationships between classes of objects.  
3. **Inheritance**: A programming technique that allows a derived class to extend the functionality of a base class, inheriting all of its state and behavior.  
4. **Superclass**: The parent class in an inheritance relationship.  
5. **Subclass**: The child class in an inheritance relationship.  
6. **Override**: Implementing a new version of a method to replace code that would otherwise have been inherited from a superclass.

### Overriding vs Overloading

- **Overriding** occurs when a subclass replaces an inherited method from a parent class.  
- **Overloading** is when a class has multiple methods with the same name but different parameter signatures.

### Notes

- A subclass cannot directly refer to any private attribute declared in the parent class.  
- A subclass must always begin with a constructor from the superclass.  
  - If not, the compiler will attempt to create a parameterless constructor for the parent class, which causes an error if such a constructor doesn't exist.

# 2. What is a Superclass?

See `Example2.java` for reference.

# 3. What is the Object Class?

The `Object` class is the parent class of all Java classes. It contains methods common to all objects, such as:

- `toString()`

# 4. How does the `equals` Method Work with Objects?

The default `equals` method checks for reference equality — it returns true only if both variables reference the exact same object.

To compare the *state* of two objects, you must override the `equals` method with your own implementation.

---

## ❗️Interesting Notes

- Java classes are automatically shared with each other if they are in the **same package**.  
  Example: In the `equalscode` package, `Point.java` was accessible without importing it.

- `instanceof` checks if a variable is an instance of a specific class.  
  Implemented in `Point.java`.

# 5. What is Polymorphism?

Polymorphism is the ability for the same code to be used with several different types of objects, where the code behaves differently depending on the actual type of the object.

# 6. What is an Interface?

An interface is like a class but only contains method headers (no method bodies). It serves as a blueprint for classes.  

- Classes that implement an interface form an **is-a** relationship by promising to provide implementations of all the methods.
- An **abstract method** is a method declared in an interface that must be implemented by any class that uses the interface.
