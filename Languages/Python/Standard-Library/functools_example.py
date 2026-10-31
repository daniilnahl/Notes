#allows constructs with a minimal amount of code

#this example shows how to configure a function to use cache with functools and to reuse the results from previous calls to speed up the overall process.
import functools
import time

#CAUSES AN ERROR
def func(x):
    time.sleep(1)
    print(f"Heavy operation for {x}")
    return x * 10

print("Func returned:", func(1))
print("Func returned:", func(1))

@functools.lru_cache()
def func_example(x):
    time.sleep(1)
    print(f"Heavy operation for {x}")
    return x * 10

print("Func returned:", func_example(1))
print("Func returned:", func_example(1))
print("Func returned:", func_example(2))

#using partial
def func(x, y, z):
    print("x:", x)
    print("y:", y)
    print("z:", z)
    
func(1, 2, 3)

new_func = functools.partial(func, z='Wops')
new_func(1, 2)