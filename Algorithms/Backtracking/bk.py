#PSEUDO CODE
def backtrack(candidates, target, currentPath):
    if (currentPath == target):
        #update answer and/or end recursion
   
    #NO INFINITE LOOP if valid means not already visited 
    for cand in candidates: #iterates over all possible candidates
        if cand is valid: #ensures cand can be added to currentPath without violating constraints.
            
            #recursively calls function
            currentPath.add(cand)
            backtrack(candidates, target, currentPath)
            currentPath.remove(cand)#remove cand to explore other solutions