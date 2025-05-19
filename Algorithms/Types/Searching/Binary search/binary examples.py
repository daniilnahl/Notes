#iterative example
def binary_search(array, target):
    left = 0 #the index 
    right = len(array) - 1
    
    while (left <= right):
        mid = (left + right) // 2 #mid is the index not the value 
        print(mid)
        if array[mid] == target: #value is called when we put mid into the index of array
            return mid 
        elif array[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
            
    return -1 #if doesnt exist
    #Complexity: log(base)2 (n) + 1

def binary_search_recursive(array, target, lower, upper):
    if lower > upper: #edge case
        return -1
    
    mid = (lower + upper) // 2

    if array[mid] == target: #value is called when we put mid into the index of array
        return mid 
    elif array[mid] < target:
        return binary_search_recursive(array, target, mid+1, upper)
    else:
        return binary_search_recursive(array, target, lower, mid-1)

print("LOOP Based binary")
print("25 is at index:",binary_search([-23, -5,  9, 14, 15, 18, 23, 24, 25, 29, 34, 62, 85, 87], 25))  
print("RECURSIVE binary")   
print("25 is at index:",binary_search_recursive([-23, -5,  9, 14, 15, 18, 23, 24, 25, 29, 34, 62, 85, 87], 25, 0, 13))
print()
#recursive example  
# Returns index of x in arr if present, else -1
def binarySearch(arr, low, high, x):

    # Check base case
    if high >= low:

        mid = low + (high - low) // 2

        # If element is present at the middle itself
        if arr[mid] == x:
            return mid

        # If element is smaller than mid, then it
        # can only be present in left subarray
        elif arr[mid] > x:
            return binarySearch(arr, low, mid-1, x)

        # Else the element can only be present
        # in right subarray
        else:
            return binarySearch(arr, mid + 1, high, x)

    # Element is not present in the array
    else:
        return -1


# Driver Code
arr = [2, 3, 4, 10, 40]
x = 10
    
# Function call
result = binarySearch(arr, 0, len(arr)-1, x)
    
if result != -1:
    print("Element is present at index", result)
else:
    print("Element is not present in array")