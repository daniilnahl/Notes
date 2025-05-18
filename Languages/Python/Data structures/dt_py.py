from collections import defaultdict

def main():
    """INFORMATION ON LISTS, DICTIONARIES, SETS AND TUPLES"""
    #LIST
    print('LIST')
    todo = ["pick up laundry", "buy Groceries", "pay electric bills"]
    print(todo, "\n", len(todo))

    list1 = [3,4,5]
    list2 = [6, 7, 8]
    print(list1 + list2)
    print(list1 * 3)

    #two dimensional list aka nested list
    x = [list1, list2]
    print(x[0][0]) #print 0 element from list1
    print(x[1][2]) #print 2 element from list2

    #matrix addition and subtraction
    Z = [[1,2,3],[4,5,6],[7,8,9]]
    B = [[10,11,12],[13,14,15],[16,17,18]]
    result = [[0,0,0],[0,0,0],[0,0,0]]
    for i in range(len(x[0])):
        for j in range(len(x[0])):
            result[i][j] = Z[i][j] + B[i][j]
    print(result)

    print('=' * 100)    
    print('=' * 100)
    print('=' * 100)

    #dictionary
    print('DICTIONARY')
     # key: value
    User = {"first_name": "Jack", "last_name":"White","age": 41, "email": "jack.white@gmail.com"}
    print(User['first_name'])

    User['age'] = User['age'] + 5
    print(User['age'])

    #dictionary with a list inside
    movie = {}
    movie['actors'] = ['Marlon Brando', 'Al Pacino','James Caan']

    #dictionary with a dictionary inside
    movie['other_details'] = {'runtime': 175,'language': 'English'}
    print(movie)

    people = {'name': ['John', 'Lisa', 'Matt'], 'age': ['12', '16', '54']}
    #len converts the index of 'name' in people into an integer
    #range takes that number to run the for loop
    for person in range(len(people['name'])):
        print('NAME:', people['name'][person])
        print('AGE:', people['age'][person])
        print()


    print('=' * 100)    
    print('=' * 100)
    print('=' * 100)

    #tuple
    print('TUPLES')

    point = ('rap', 'classical', 'rock')
    print(point, len(point))

    #only way to modify a tuple is to create a new tuple and combine with desired items
    point2 = (point, 'hip-hop', 'jazz') #doesnt really do what intended. It makes tuple point just the first element of this tuple
    print(point2)

    other_tuple = (('day', True), ('Mike', 'Dick'), ('12', 12))
    print(other_tuple, '\n')

    print('=' * 100)    
    print('=' * 100)
    print('=' * 100, '\n')

    #zip

    name = ['Mike', 'John', 'Luke']
    age = [12, 54, 2]
    persons = zip(name, age)
    print(persons, '\n')
    #print(tuple(persons)) turns zip into tuple
    #print(list(persons)) turns zip into list
    #print(dict(persons)) turns zip into dictionary

    print('=' * 100)    
    print('=' * 100)
    print('=' * 100)


    #set
    s1 = set([1,2,3,4]) #set and {} work equally the same to create a set
    print(s1)
    s2 = {3,4,5,6}
    print(s2)

    new_set = {'apple', 'dog', 'cat', 'love'}
    print(new_set)
    new_set.add('Micheal Jordan')
    print(new_set)

    #union
    print(s1 | s2) 
    print(s1.union(s2))

    #intersection
    print(s1 & s2)
    print(s1.intersection(s2))

    #difference, <=, >=
    print(s1 - s2)
    print(s1 <= s2) #false because sets dont match 
    print(s1 >= {1,2,3,4}) #true becuase sets match
    print(s1 > {1,2,3,4}) #false because s1 doesn't have any other elements besides those that match
    print({1,2,3,4,5} > {1,2,3,4}) #true because sets match and first set has other elements besdies those that match


#LIST COMP
#normal way
cubes = []
for x in [1,2,3,4,5]:
    cubes.append(x**3)
print(cubes)

#pythonic way (list comprehension)
cubes = [x**3 for x in range(1,6)]
print(cubes)

#LIST COMPRENSION WITH IF AND ELSE
[AX if condition else AB for x in iterable]

#string example
names = ["Graham Chapman", "John Cleese", "Terry Gilliam", "Eric Idle", "Terry Jones"]
print([name.upper() for name in names if name.startswith("T")])

#example of two lists
print([x*y for x in ['spam', 'eggs', 'chips'] for y in [1,2,3]])
print([x*y for x in [1,2,3] for y in ['spam', 'eggs','chips']])

#practice
print([f'{x} vs {y}' for x in ['Magnus Carlsen', 'Fabiano Caruana', 'Yifan Hou', 'Wenjun Ju'] for y in ['Magnus Carlsen', 'Fabiano Caruana', 'Yifan Hou', 'Wenjun Ju'] if x != y])

#difference between list and set showcase
print([a + b for a in [0,1,2,3] for b in [4,3,2,1]])
print({a+b for a in [0,1,2,3] for b in [4,3,2,1]})

#practice
listt = ["Vivian", "Daniil", "Guy"]
scores = [32, 91, 100]

print({listt[i]:scores[i] for i in range(3)})#dictionary

#dafultdict example. Gives a default value to use for a key when a key is missing in a dictionary
john = {'first_name': 'John', 'surname': 'Cleese'}
#john['middle_name'] gives key error
safe_john = defaultdict(lambda: 'Such key doesn''t exist')#
print(safe_john["middle_name"]) #prevents keyerror exception

# ExPLANATION FROM THE BOOK
# "The benefit of the default dictionary is that in situations where you know it is likely that expected
# keys will be missing from a dictionary, you can work with default values and not have to sprinkle
# your code with exception-handling blocks. This is another example of Pythonicity: if what you mean
# is “use the value for the “foo” key, but if that doesn’t exist, then use “bar” as the value,” then you should
# write that, rather than “use the value for the “foo” key, but if you get an exception and the exception is
# KeyError, then use “bar” as the value.”








if __name__ == "__main__":
    main()