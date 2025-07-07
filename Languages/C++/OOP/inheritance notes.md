### What is inheritance?
An OOP concept that allows classes to inherit parameters and functions from other classes. 

- Base class: where inherited from.
- Derived class: class that inherited from base class.

### Why is it improtant?

### How does it work?
**Access Specifiers**
- private: only the class itself can access.
- protected: the class itself and its derived classes can access.
- public: the class itself, derived classes, and outside the classes can access.


To create an inheritance relationship do this:
```
class State : public Country {...
```
Dervied classes inherit everything from base class. If you want to explicitly state that a derived class must define a function from base class on its own, you must add **virtual** prefix.

```
virtual int get_gdp();
```

In the derived class the function must be defined like this:
```
virtual int get_gdp() override;
```

### When to use it?