def find_smallest(arr):
    smallest = arr[0] #stores the smallest value
    smallest_index = 0 #stores the index of the smallest value
    for i in range(1,len(arr)):
        if arr[i] < smallest:
            smallest = arr[i]
            smallest_index = i
    
    return smallest_index

#we use previous function to write a selection sort
def selection_sort(arr):
    new_arr = []
    for i in range(len(arr)):
        print(new_arr)
        smallest = find_smallest(arr)
        new_arr.append(arr.pop(smallest)) #.pop removes the item at the given position in the list, and returns it.
    return new_arr

print(selection_sort([5, 2, 6, 10, 12, -1]))
    


