# How to clear input buffer after cin?
Use this code:
```
cin.ignore(numeric_limits<streamsize>::max(), '\n');
```