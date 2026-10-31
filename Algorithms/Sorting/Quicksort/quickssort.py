#Big O depends on the pivot you choose. Choose a random element.
#Worst case:  O(n).  Best case: O(log n)

#quick sort on an array
#First step - pick an element from an array (called pivot).
#Second step - Partition the array into two sub-arrays: elements less than the pivot and elements greater than the pivot.
#       aka (find the elements smaller and the elements that are bigger than the pivot: called partitioning). By now you should have a pivot, a sublist of smaller elements and a sublist of bigger elements.
#Third step - call quicksort recursively on the two sub-arrays.

def quicksort(array: list):
    if len(array) < 2:
        return array
    else:
        pivot = array[0] #recursive case
        less = [i for i in array[1:] if i <= pivot] #less than pivot
        greater = [i for i in array[1:] if i > pivot] #greate than pivot
        
        return quicksort(less) + [pivot] + quicksort(greater)
    
print(quicksort([10, 5, 11, 3]))