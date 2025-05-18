### What are list comprehensions?
    List comprehension is basically a one line loop that creates a list based on some conditions. Example in file.

### What is a set?
    Set is a an unordered collection: you can see what elements are in a set, but you cannot index into a set nor
    insert an object at a particular location in the set because the elements are not ordered. An element
    can only be present in a set once, whereas it could appear in a list multiple times.

    Example use of set:
    A web service might keep track of all of the active session tokens in a set so that when it receives a request, it can test
    whether the session token corresponds to an active session.

### What is the difference between set and dictionary comprehension?
    They are very similiar since they yse {} instead of [], so be careful. 
    In a set:
        { x for x in … }
    In a dictionary:
        { key:value for key in… }
