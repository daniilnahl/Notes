# What is a typedef?
Typedef creates an alias for a simple or structured data type.
```
typedef {existing type} {new name};
```

# When to use typedef?
Use it to make code more readable and create aliases for data strucutres for specific purpose. Like a vector that holds values of bank account balance could be made into:
```
typdef std::vector<double> bank_balances;
```